
NAME			= minishell

CC				= cc
CFLAGS			= -g3 -fsanitize=address -Wall -Wextra -Werror
RM				= rm -rf

LIB_READ		= -l readline
LDFLAGS			= -L$(shell brew --prefix readline)/lib
CPPFLAGS		= -I$(shell brew --prefix readline)/include

LIB_DIR			= lib/
LIBFT			= libft/libft.a
# HEADERS			= includes

MAIN			= main
BUILTIN			= ft_echo \
				ft_export \
				ft_unset \
				ft_env \
				ft_pwd \
				ft_cd \
				ft_exit
EXEC			= execution
ERROR			= error
SIG				= sig_handler

SRCS 			= $(addsuffix .c, $(addprefix src/, $(MAIN))) \
					$(addsuffix .c, $(addprefix src/signal/, $(SIG))) \
					$(addsuffix .c, $(addprefix src/error/, $(ERROR))) \
					$(addsuffix .c, $(addprefix src/executer/, $(EXEC))) \
					$(addsuffix .c, $(addprefix src/builtin/, $(BUILTIN)))\

OBJS 			= $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -j -C $(LIB_DIR)/libft
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_DIR)/$(LIBFT) $(LIB_READ) $(LDFLAGS) $(CPPFLAGS)
	@make -j fclean -C $(LIB_DIR)/libft

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
