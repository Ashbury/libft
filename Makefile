NAME = libft.a
FLAGS = -Wall -Wextra -Werror -Weverything -Ofast
INC = includes/
COMPILATION = clang $(FLAGS) -I$(INC)
SRCS_DIR = ./srcs

FT_PRINTF_DIR =		ft_printf
FT_PRINTF_FILES =	buffer_add_char.o\
					buffer_add_signed.o\
					buffer_add_string.o\
					buffer_add_unsigned.o\
					conv_char.o\
					conv_invalid.o\
					conv_percent.o\
					conv_pointer.o\
					conv_signed.o\
					conv_string.o\
					conv_unicode_char.o\
					conv_unicode_string.o\
					conv_unsigned.o\
					fill_buffer.o\
					ft_dprintf.o\
					ft_printf_is_flag.o\
					ft_printf_is_size.o\
					ft_printf.o\
					get_signed_value.o\
					get_unicode_char_width.o\
					get_unsigned_value.o\
					parse_argument.o\
					treat_argument.o\

FT_MALLOC_DIR =		ft_malloc
FT_MALLOC_FILES =	align.o\
					ft_calloc.o\
					ft_find_page.o\
					ft_find_zone.o\
					ft_free.o\
					ft_malloc.o\
					ft_realloc.o\
					ft_reallocf.o\
					memory_logs.o\
					pages.o\
					pre_mapper.o\
					printing_tools.o\
					unmapper.o\
					zones.o

CONVERSIONS_DIR =	conversions
CONVERSIONS_FILES =	ft_atoi.o\
					ft_itoa.o\
					ft_tolower.o\
					ft_toupper.o\
					get_signed_width.o\
					get_unsigned_width.o\
					signed_to_string.o\
					unsigned_to_string.o

IDENTIFICATION_DIR =	identification
IDENTIFICATION_FILES =	ft_isalnum.o\
						ft_isalpha.o\
						ft_isascii.o\
						ft_isdigit.o\
						ft_isprint.o\
						ft_isspace.o\
						ft_isupper.o\
						ft_islower.o

MEMORY_DIR =	memory
MEMORY_FILES =	address_cmp.o\
				ft_bzero.o\
				ft_memalloc.o\
				ft_memccpy.o\
				ft_memchr.o\
				ft_memcmp.o\
				ft_memcpy.o\
				ft_memdel.o\
				ft_memmove.o\
				ft_memset.o\
				ft_memswap.o\
				ft_free_db_array.o\
				ft_n_free.o\
				free_and_return.o

INT_OUT_DIR =	in_out
INT_OUT_FILES =	ft_putchar.o\
				ft_putchar_fd.o\
				ft_putendl.o\
				ft_putendl_fd.o\
				ft_putnbr.o\
				ft_putnbr_fd.o\
				ft_putstr.o\
				ft_putstr_fd.o

STRINGS_DIR =	strings
STRINGS_FILES =	ft_strcat_end.o\
				ft_strcat.o\
				ft_strchr.o\
				ft_strclr.o\
				ft_strcmp.o\
				ft_strcpy.o\
				ft_strcspn.o\
				ft_strcpy_noend.o\
				ft_strdel.o\
				ft_strdup.o\
				ft_strequ.o\
				ft_striter.o\
				ft_striteri.o\
				ft_strjoin.o\
				ft_strlcat.o\
				ft_strlen.o\
				ft_strmap.o\
				ft_strmapi.o\
				ft_strncat.o\
				ft_strnchr.o\
				ft_strncmp.o\
				ft_strncpy.o\
				ft_strnequ.o\
				ft_strnew.o\
				ft_strnstr.o\
				ft_strsplit.o\
				ft_strspn.o\
				ft_strrchr.o\
				ft_strstr.o\
				ft_strsub.o\
				ft_strtrim.o\
				ft_strrep.o\
				ft_strrev.o\
				ft_strndup.o\
				ft_strnb.o\
				ft_strchrpos.o\
				ft_strtok.o

LISTS_DIR =		lists
LISTS_FILES =	clean_elem.o\
				ft_lstparent.o\
				ft_lstremove.o\
				ft_lstmerge_sort.o\
				ft_lstnew.o\
				ft_lstdelone.o\
				ft_lstdel.o\
				ft_lstadd.o\
				ft_lstiter.o\
				ft_lstmap.o

MATHS_DIR =		maths
MATHS_FILES =	ft_int_sqrt.o\
				ft_pow.o\
				ft_sqrtup.o

UTILITY_DIR =	utility
UTILITY_FILES =	establish_connexion.o\
				ft_qsort.o\
				ft_tabrev.o\
				get_next_line.o\
				print_and_return.o\
				rev_endian_16.o\
				rev_endian_32.o\
				rev_endian_64.o

OBJS_DIR =	./objs

ALL_DIR =	$(OBJS_DIR) \
			$(OBJS_DIR)/$(FT_PRINTF_DIR)\
			$(OBJS_DIR)/$(FT_MALLOC_DIR)\
			$(OBJS_DIR)/$(CONVERSIONS_DIR)\
			$(OBJS_DIR)/$(IDENTIFICATION_DIR)\
			$(OBJS_DIR)/$(MEMORY_DIR)\
			$(OBJS_DIR)/$(INT_OUT_DIR)\
			$(OBJS_DIR)/$(STRINGS_DIR)\
			$(OBJS_DIR)/$(LISTS_DIR)\
			$(OBJS_DIR)/$(MATHS_DIR)\
			$(OBJS_DIR)/$(UTILITY_DIR)

ALL_OBJ=	$(FT_PRINTF_FILES:%.o=$(OBJS_DIR)/$(FT_PRINTF_DIR)/%.o) \
			$(FT_MALLOC_FILES:%.o=$(OBJS_DIR)/$(FT_MALLOC_DIR)/%.o) \
			$(CONVERSIONS_FILES:%.o=$(OBJS_DIR)/$(CONVERSIONS_DIR)/%.o) \
			$(IDENTIFICATION_FILES:%.o=$(OBJS_DIR)/$(IDENTIFICATION_DIR)/%.o) \
			$(MEMORY_FILES:%.o=$(OBJS_DIR)/$(MEMORY_DIR)/%.o) \
			$(INT_OUT_FILES:%.o=$(OBJS_DIR)/$(INT_OUT_DIR)/%.o) \
			$(STRINGS_FILES:%.o=$(OBJS_DIR)/$(STRINGS_DIR)/%.o) \
			$(LISTS_FILES:%.o=$(OBJS_DIR)/$(LISTS_DIR)/%.o) \
			$(MATHS_FILES:%.o=$(OBJS_DIR)/$(MATHS_DIR)/%.o) \
			$(UTILITY_FILES:%.o=$(OBJS_DIR)/$(UTILITY_DIR)/%.o)

all: $(NAME)

all_dir: $(ALL_DIR)

$(ALL_DIR):
	mkdir -p $@

%.c:

$(NAME): $(ALL_DIR) $(ALL_OBJ)
	ar rc $(NAME) $(ALL_OBJ)
	ranlib $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(COMPILATION) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all all_dir clean fclean re
