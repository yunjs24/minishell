/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:19:30 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/04 16:34:04 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	minishell_loop()
{
	char	*line;

	signal(SIGINT, sig_set_readline);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("msh$ ");
		add_history(line);
		
	}
}

static char	*display_prompt()
{
	// char	*line;
	return NULL;
}

int	main(int argc, char **argv, char **env)
{
	// char	*commands;
	// char	*input;
	// int		ret;

	(void)(argc);
	(void)(argv);
	(void)(env);
	minishell_loop();
}
