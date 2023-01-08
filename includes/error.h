#ifndef ERROR_H
# define ERROR_H

void		error_push(char *msg);
void		ft_perror(char *err_msg1, char *err_msg2);
int			check_syntax_error(t_token *token);

#endif