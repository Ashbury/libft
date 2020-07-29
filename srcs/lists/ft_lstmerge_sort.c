/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:03:16 by justasze          #+#    #+#             */
/*   Updated: 2018/10/06 14:06:45 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		swap(t_list **a, t_list **b, t_list ***indirect)
{
	**indirect = *a;
	*indirect = &((*a)->next);
	*a = (*a)->next;
	if (*a == NULL)
	{
		**indirect = *b;
		return (1);
	}
	return (0);
}

static t_list	*merge(t_list *head1, t_list *head2, int (*f)(void *, void *))
{
	t_list	*head_three;
	t_list	**indirect;

	indirect = &head_three;
	if (head1 == NULL)
		return (head2);
	if (head2 == NULL)
		return (head1);
	while (1)
	{
		if (f(head1->content, head2->content) <= 0)
		{
			if (swap(&head1, &head2, &indirect) == 1)
				break ;
		}
		else if (swap(&head2, &head1, &indirect) == 1)
			break ;
	}
	return (head_three);
}

t_list			*ft_lstmerge_sort(t_list *head, int (*f)(void *, void *))
{
	t_list	*head_one;
	t_list	*head_two;

	if (head == NULL || head->next == NULL)
		return (head);
	head_one = head;
	head_two = head->next;
	while (head_two != NULL && head_two->next != NULL)
	{
		head_one = head_one->next;
		head_two = head_two->next->next;
	}
	head_two = head_one->next;
	head_one->next = NULL;
	return (merge(ft_lstmerge_sort(head, f), ft_lstmerge_sort(head_two, f), f));
}
