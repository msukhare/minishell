# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msukhare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 15:46:51 by msukhare          #+#    #+#              #
#    Updated: 2018/02/24 13:35:31 by msukhare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/

SRC_NAME = main.c\
	   ft_managelst.c\
	   ft_cd.c\
	   ft_check_bin.c\
	   ft_cpa.c\
	   ft_createnv.c\
	   ft_echo.c\
	   ft_env.c\
	   ft_error.c\
	   ft_execbin.c\
	   ft_generatenv.c\
	   ft_getarg.c\
	   ft_getcmd.c\
	   ft_getforcd.c\
	   ft_getfree.c\
	   ft_managecmd.c\
	   ft_printenv.c\
	   ft_setenv.c\
	   ft_unsetenv.c\
	   ft_putloca.c\
	   ft_check_forcd.c\

OBJ_PATH = obj/

CPPFLAGS = -I includes/ -I libft/include/

NAME = minishell

CC = gcc

MK = make -C

SRCLFT = libft/

LFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(MK) $(SRCLFT)
	$(CC) $(CFLAGS) -o $(NAME) $(CPPFLAGS) $(OBJ) $(LFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C $(SRCLFT)
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C $(SRCLFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
