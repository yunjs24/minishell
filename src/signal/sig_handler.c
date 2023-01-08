#include "../../includes/minishell.h"

void	sig_set_readline(int sig)
{
	if (sig == SIGINT)
	{
		printf("\ntest: sig_set_readline called!\n");
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	sig_exec(int sig)
{
	if (sig == SIGINT)
		printf("\n");
	else if (sig == SIGQUIT)
		printf("Quit!\n");
}
