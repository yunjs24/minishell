#include "../../includes/minishell.h"

int	execution()
{
	int		status;
	t_rdhd	rdhd;

	status = EXIT_SUCCESS;
	rdhd.h_token = NULL;
	signal(SIGINT, &sig_exec);
	signal(SIGQUIT, &sig_exec);
	return (0);
}

int		exec_line(char *line)
{
	int		status;
	t_rdhd	rdhd;

	status = EXIT_SUCCESS;
	rdhd.h_token = NULL;
	tokenizer(&(rdhd.h_token), line);
	if (check_syntax() == SUCCESS && \
		rd_hd_check() == SUCCESS)
	return (0);
}
