#ifndef BUILTIN_H
# define BUILTIN_H

int	ft_echo(t_token *token);
int	ft_export(t_token *token);
int	ft_unset(t_token *token);
int	ft_env(t_token *token);
int	ft_pwd(t_token *token);
int	ft_cd(t_token *token);
int	ft_exit(t_token *token);

#endif
