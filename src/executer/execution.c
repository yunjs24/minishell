#include "../../includes/minishell.h"

int	execution()
{
	int	status;

	status = EXIT_SUCCESS;
	signal(SIGINT, &sig_exec);
	signal(SIGQUIT, &sig_exec);
	return (0);
}

int		exec_line(char *line)
{
	(void)line;
	return (0);
}
