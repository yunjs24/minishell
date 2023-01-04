#include "minishell.h"

int	execution()
{
	int	status;

	status = EXIT_SUCCESS;
	signal(SIGINT, &sig_exec);
	signal(SIGQUIT, &sig_exec);

}
