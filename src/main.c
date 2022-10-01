/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:19:30 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/02 04:35:18 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	**commands;
	char	*input;
	int		ret;

	while (1)
	{
		display_prompt();
		signal(SIGINT, signal_handler);
	}
}