#ifndef PARSER_H
# define PARSER_H

t_token	*check_quote(int *idx, char *line);
t_token *check_parens(int *idx, char *line);
t_token *check_and_or_pipe(int *idx, char *line);
t_token *check_redir(int *idx, char *line);
t_token *check_cmd_option(int *idx, char *line);

void	tokenizer(t_token **tokens, char *line);

#endif