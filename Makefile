# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:51:31 by ayguillo          #+#    #+#              #
#    Updated: 2019/02/13 14:52:03 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECHECK = checker
NAMEPS = push_swap
LIBFT = lib

CC = @ gcc 

CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address

RED=$'\x1b[31m
GREEN=$'\x1b[32m
END=$'\x1b[0m

SRCS = srcs/ft_instructions.c \
	   srcs/ft_list.c \
	   srcs/ft_pars.c \

SRCSCHECK = srcscheck/main.c \
			srcscheck/ft_checker.c \
			srcscheck/ft_visu.c \

SRCSPS = srcsps/ft_init_instructions.c \
		 srcsps/numbers.c \
		 srcsps/main.c \
		 srcsps/ft_shortsorts.c \
		 srcsps/ft_insertsort.c \
		 srcsps/ft_opti.c \
		 srcsps/ft_optirb.c \

OBJS = $(SRCS:.c=.o)

OBJSCHECK = $(SRCSCHECK:.c=.o)

OBJSPS = $(SRCSPS:.c=.o)

all : $(LIBFT) $(NAMEPS) $(NAMECHECK)

$(LIBFT) :
	@make -C libft

$(NAMECHECK) : $(OBJSCHECK) $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAMECHECK) $(OBJSCHECK) $(OBJS) libft/libft.a
	@echo "$(GREEN)$(NAMECHECK) compiled ✔$(END)"

$(NAMEPS) : $(OBJSPS) $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAMEPS) $(OBJSPS) $(OBJS) libft/libft.a
	@echo "$(GREEN)$(NAMEPS) compiled ✔$(END)"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean : 
	@make clean -C libft
	@rm -f $(OBJS) $(OBJSCHECK) $(OBJSPS)
	@echo "$(RED)Push_swap objects deleted ✕$(END)"

fclean : clean 
	@make fclean -C libft
	@rm -f $(NAMECHECK) $(NAMEPS)
	@echo "$(RED)$(NAMECHECK) deleted ✕$(END)"

re : fclean all

.PHONY : all clean fclean re
