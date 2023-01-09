#include "../../includes/minishell.h"

int	check_syntax(t_token *token)
{
	if (!token)
		return (FALSE);
	if (token->type == AND || token->type == OR || token->type == PIPE)
	{
		perror("perror called");
		return (FALSE);
	}
	return (valid_token(token));
}

static int	vaild_next_token(int prev_type, int cur_type)
{
	if (((prev_type == CMD) && (cur_type == PARENS))	|| \
		((prev_type == PARENS) && (cur_type == CMD))	||\
		((prev_type == PARENS) && (cur_type == PARENS)))
		return (FALSE);
	if ((prev_type >= RDIR_STDIN && prev_type <= HERE_DOC) && \
		!(cur_type >= CMD && cur_type <= SM_QUOTE))
		return (FALSE);
	if ((prev_type >= OR && prev_type <= PIPE) && \
		(cur_type >= OR && cur_type <= PIPE))
		return (FALSE);
	return (SUCCESS);
}

static int	valid_token(t_token *token)
{
	t_token *tmp;
	t_token *prev;


	tmp = token;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
		if (valid_next_token(prev->type, tmp->type) == FALSE)
		{
			if (prev->type >= RDIR_STDIN && prev->type <= HERE_DOC)
				error_syntax(token->content);
			else
				error_syntax(token->content);
			return (FALSE);
		}
	}
	if (!(tmp->type >= CMD && tmp->type <= SM_QUOTE) && tmp->type != PARENS)
	{
		error_syntax(token->content);
		return (FALSE);
	}
	return (SUCCESS);
}
