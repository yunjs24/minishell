#include "../../include/minishell.h"

int	ft_exit(t_token *token)
{
	int	code;

	(void)(token);
	code = 0;
	exit(code);
}