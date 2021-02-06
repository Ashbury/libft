/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maven <maven@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 19:52:10 by justasze          #+#    #+#             */
/*   Updated: 2019/07/03 12:56:53 by maven            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H

# define PROTOTYPES_H

# include "libft.h"

/*
** CONVERSIONS
*/

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		get_signed_width(ssize_t nbr, ssize_t base);
size_t		get_unsigned_width(size_t nbr, size_t base);
char		*signed_to_string(ssize_t nbr, char *base, ssize_t base_len);
char		*unsigned_to_string(size_t nbr, char *base, size_t base_len);

/*
**IDENTIFICATION
*/

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
int			ft_isspace(int n);

/*
**IN_OUT
*/

void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putendl_fd(const char *str, int fd);
void		ft_putendl(const char *str);
void		ft_putnbr_fd(int32_t n, int fd);
void		ft_putnbr(int32_t n);
void		ft_putstr_fd(const char *str, int fd);
void		ft_putstr(const char *s);

/*
**LISTS
*/

void		clean_elem(void *content, size_t size);
void		ft_lstadd(t_list **alst, t_list *new_list);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstmerge_sort(t_list *head, int (*f)(void *, void *));
t_list		*ft_lstnew(void const *content, size_t content_size);
t_list		*ft_lstparent(t_list *lst, t_list *item);
void		ft_lstremove(t_list **indirect, t_list *entry);

/*
**MATHS
*/

int			ft_int_sqrt(int n);
long		ft_pow(long nbr, int pwr);
int			ft_sqrtup(int n);

/*
**MEMORY
*/

int			address_cmp(void *a, void *b);
int			free_and_return(void *str, int ret);
void		ft_bzero(void *ptr, size_t len);
void		ft_free_db_array(char **tab);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_memswap(void *m1, void *m2);
void		ft_n_free(int n, ...);

/*
**STRINGS
*/

char		*ft_strcat_end(char *str1, const char *str2);
char		*ft_strcat(char *str1, const char *str2);
char		*ft_strchr(char *str, int c);
size_t		ft_strchrpos(const char *str, const char c);
void		ft_strclr(char *str);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strcpy_noend(char *dst, const char *src);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strcspn(char *str1, char *str2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *str1);
int			ft_strequ(const char *str1, const char *str2);
void		ft_striter(char *str, void (*f)(char *));
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
char		*ft_strjoin(const char *str1, const char *str2);
size_t		ft_strlcat(char *str1, const char *str2, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
size_t		ft_strnb(char *str, char c);
char		*ft_strncat(char *str1, const char *str2, size_t n);
char		*ft_strnchr(char *str, int c, unsigned int n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strndup(const char *str, size_t n);
int			ft_strnequ(const char *str1, const char *str2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(char *str1, char *str2, size_t n);
char		*ft_strrchr(char *str, int c);
void		ft_strrep(char *str, char c, char rep);
char		*ft_strrev(char *str);
char		**ft_strsplit(const char *s, char c);
size_t		ft_strspn(char *str1, char *str2);
char		*ft_strstr(char *str1, char *str2);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
char		*ft_strtok(char *str, char *delim);
char		*ft_strtrim(const char *s);

/*
**UTILITY
*/

int			establish_connexion(int *sock, char *server, char *service,
				struct addrinfo *hints);
void		ft_qsort(void *array, size_t len, size_t width,
				int (*cmp)(const void *, const void *));
void		ft_tabrev(char **s, int len);
int			print_and_return(char *str, int fd, int ret);
uint16_t	rev_endian_16(uint16_t value);
uint32_t	rev_endian_32(uint32_t value);
uint64_t	rev_endian_64(uint64_t value);

#endif
