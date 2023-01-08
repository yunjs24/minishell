# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 04:29:34 by junsyun           #+#    #+#              #
#    Updated: 2023/01/09 05:59:36 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= minishell

CC				= cc
CFLAGS			= -g -Wall -Wextra -Werror -fsanitize=address
RM				= rm -rf

LIB_READ		= -l readline
LDFLAGS			= -L$(shell brew --prefix readline)/lib
CPPFLAGS		= -I$(shell brew --prefix readline)/include
# LDFLAGS			= -L./readline/lib
# CPPFLAGS		= -I./readline/include
# LDFLAGS			= -Lreadline/8.2.1/lib
# CPPFLAGS		= -Ireadline/8.2.1/include

LIB_DIR			= lib/
LIBFT			= libft/libft.a
HEADERS			= include

MAIN			= main
BUILTIN			= ft_echo \
				ft_export \
				ft_unset \
				ft_env \
				ft_pwd \
				ft_cd \
				ft_exit
EXEC			= execution
SIG				= sig_handler

SRCS 			= $(addsuffix .c, $(addprefix src/, $(MAIN))) \
					$(addsuffix .c, $(addprefix src/executer/, $(EXEC))) \
					$(addsuffix .c, $(addprefix src/signal/, $(SIG))) \
					$(addsuffix .c, $(addprefix src/builtin/, $(BUILTIN)))
OBJS 			= $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -j -C $(LIB_DIR)/libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_DIR)/$(LIBFT) $(LIB_READ) $(LDFLAGS) $(CPPFLAGS)

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
