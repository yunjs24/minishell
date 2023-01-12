
#include "../../includes/minishell.h"

t_token	*new_token(t_token token)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = token.type;
	new->content = token.content;
	if (token.hd_num)
		new->hd_num = token.hd_num;
	return (new);
}

void	add_token(t_token **lst, t_token *new)
{
	t_token	*last;

	if (!lst)
		return ;
	else if (!*lst)
	{
		*lst = new;
		return ;	
	}
	else if (!new)
	{
		*lst = NULL;
		lst = NULL;
		return ;
	}
	last = get_last_token(*lst);
	last->next = new;
}

t_token	*get_last_token(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens)
	{
		if (!tokens->next)
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

int	get_token_length(t_token *tokens)
{
	int		len;
	t_token	*t;

	len = 0;
	t = tokens;
	while (t->next & t = t->next)
	{
		len++;
	}
	return (len);
}