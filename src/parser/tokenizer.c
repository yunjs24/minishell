/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:09:39 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/12 18:26:38 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	pass_space(int *idx, char *line)
{
	int	i;

	i = *idx;
	while (line[i] && line[i] == ' ')
		i++;
	*idx = i;
}

static void	tab_to_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}

void	tokenizer(t_token **tokens, char *line)
{
	int		i;
	int		len;
	char	*trimed_line;

	i = 0;
	tab_to_space(line);
	trimed_line = ft_strtrim(line, "");
	len = ft_strlen(trimed_line);
	while (line[i] && i < len)
	{
		if (ft_strchr("\'\"", trimed_line[i]))
			add_token(tokens, check_quote(&i, trimed_line));
		else if (ft_strchr("()", trimed_line[i]))
			add_token(tokens, check_parens(&i, trimed_line));
		else if (ft_strchr("|&", trimed_line[i]))
			add_token(tokens, check_and_or_pipe(&i, trimed_line));
		else if (ft_strchr("<>", trimed_line[i]))
			add_token(tokens, check_redir(&i, trimed_line));
		else
			add_token(tokens, check_cmd_option(&i, trimed_line));
		pass_space(&i, trimed_line);
		if (!*tokens)
			break ;
	}
}
