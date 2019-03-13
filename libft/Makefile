# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:51:31 by ayguillo          #+#    #+#              #
#    Updated: 2019/02/13 10:39:36 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = ./includes/

CC = @ gcc 

CFLAGS = -g -c -I $(INCLUDES) -Wall -Wextra -Werror

RED=$'\x1b[31m
GREEN=$'\x1b[32m
END=$'\x1b[0m

SRCPRINTF = ft_printf/

SRC = ft_atoi.c \
	  ft_atol.c \
	  ft_abs.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_isdigitsign.c \
	  ft_strcat.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnstr.c \
	  ft_strstr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memalloc.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strclr.c \
	  ft_strdel.c \
	  ft_strnew.c \
	  ft_memalloc.c \
	  ft_realloc.c \
	  ft_memdel.c \
	  ft_memset.c\
	  ft_putstr.c \
	  ft_striter.c  \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_str_joinfree.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_putchar.c \
	  ft_itoa.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putnbr_base.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_putnstr.c \
	  ft_strclen.c \
	  ft_strndup.c \
	  ft_strcdup.c \
	  ft_sqrt.c \
	  ft_pow.c \
	  ft_gnl.c \
	  ft_print_words_tables.c \
	  ft_lstdelcontent.c \
	  ft_lstclearifdata.c \
	  ft_putlst.c \
	  ft_lstlen.c \
	  ft_lstclear.c

PRINTF_SRCS = capture_the_flag.c \
			  check_error.c \
			  check_flag_hl.c \
			  dispatcher.c \
			  flag_0.c \
			  flag_hash.c \
			  flag_plus_space.c \
			  flag_precision.c \
			  flag_space_char.c \
			  flag_space_nb.c \
			  flag_space_neg.c \
			  ft_nblen.c \
			  ft_nblen_unsign.c \
			  ft_print_char.c \
			  ft_print_float.c \
			  ft_print_hex.c \
			  ft_print_number.c \
			  ft_print_octal.c \
			  ft_print_percent.c \
			  ft_print_string.c \
			  ft_print_uhex.c \
			  ft_print_uhexmaj.c \
			  ft_print_unsign.c \
			  ft_printf.c \
			  ft_putnbr_base_addr.c \
			  ft_putnbr_basemaj.c \
			  ft_putnbr_double.c \
			  ft_putnbr_unsign.c \
			  get_precision.c \
			  get_space_number.c \
			  increment.c \
			  save_spaceprintnumb.c \
			  unsigned_flag_plus_space.c \

OBJSRC = $(SRC:.c=.o)
OBJPRINTF = $(addprefix ft_printf/, $(PRINTF_SRCS:.c=.o))

OBJ = $(OBJSRC) $(OBJPRINTF)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME) compiled ✔$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@/bin/rm -f $(OBJ)
	@echo "$(RED)Objects deleted ✕$(END)"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted ✕$(END)"

re : fclean $(NAME)
