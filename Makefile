# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:51:31 by ayguillo          #+#    #+#              #
#    Updated: 2019/01/21 16:02:32 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECHECK = checker
NAMEPS = push_swap
LIBFT = lib

CC = @ gcc 

CFLAGS = -Wall -Wextra -Werror

RED=$'\x1b[31m
GREEN=$'\x1b[32m
END=$'\x1b[0m

SRCS = srcs/ft_instructions.c \
	   srcs/ft_list.c \

SRCSCHECK = srcscheck/main.c \
			srcscheck/ft_checker.c \

OBJS = $(SRCS:.c=.o)

OBJSCHECK = $(SRCSCHECK:.c=.o)

all : $(TESTNAME) $(NAMECHECK) $(LIBFT)

$(LIBFT) :
	@make -C libft

$(TESTNAME) : $(OBJS)
	$(CC) $(CFLAGS) -g -o $(TESTNAME) $(OBJS) libft/libft.a
	@echo "$(GREEN)$(TESTNAME) compiled ✔$(END)"

$(NAMECHECK) : $(OBJSCHECK) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAMECHECK) $(OBJSCHECK) $(OBJS) libft/libft.a
	@echo "$(GREEN)$(NAMECHECK) compiled ✔$(END)"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean :
	@make clean -C libft
	@rm -r $(OBJS) $(OBJSCHECK)
	@echo "$(RED)Push_swap objects deleted ✕$(END)"

fclean : clean
	@make fclean -C libft
	@rm -r $(NAMECHECK)
	@echo "$(RED)$(NAMECHECK) deleted ✕$(END)"

re : fclean all
	@make re -C libft

.PHONY : all clean fclean re
