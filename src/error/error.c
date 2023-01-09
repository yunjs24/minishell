#include "../../includes/minishell.h"

void	error_push(char *msg)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	error_syntax(char *content)
{
	char	*err_syn_msg;
	char	*join_msg;

	err_syn_msg = "syntax error near unexpected token `";
	join_msg = ft_strjoin(content, "\'");
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(err_syn_msg, STDERR_FILENO);
	ft_putendl_fd(join_msg, STDERR_FILENO);
	free(join_msg);
}
