# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 04:29:34 by junsyun           #+#    #+#              #
#    Updated: 2023/01/04 16:31:31 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= minishell

CC				= cc
CFLAGS			= -fsanitize=address -Wall -Wextra -Werror
RM				= rm -rf

LIB_READ		= -l readline
LDFLAGS			= -L$(shell brew --prefix readline)/lib
CPPFLAGS		= -I$(shell brew --prefix readline)/include

LIB_DIR			= lib/
LIBFT			= libft/libft.a
HEADERS			= includes

MAIN			= main
BUILTIN			= ft_echo \
				ft_export \
				ft_unset \
				ft_env \
				ft_pwd \
				ft_cd \
				ft_exit
EXEC			= excution
SIG				= sig_handler

SRCS 			= $(addsuffix .c, $(addprefix src/, $(MAIN))) \
					$(addsuffix .c, $(addprefix src/excution/, $(EXEC))) \
					$(addsuffix .c, $(addprefix src/parser/, $(SIG))) \
					$(addsuffix .c, $(addprefix src/builtin/, $(BUILTIN)))
OBJS 			= $(SRCS:c=o)
all: $(NAME)

$(NAME): $(OBJS)
	@make -j -C $(LIB_DIR)/libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_DIR)/$(LIBFT) $(LIB_READ)  $(CPPFLAGS)

%.o: %.c $(HEADERS)/$(NAME).h
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
