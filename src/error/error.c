#include "../../includes/minishell.h"

void	error_push(char *msg)
{
	ft_putstr_fd("[Error] : ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}
