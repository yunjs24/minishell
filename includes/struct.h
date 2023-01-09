#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_global
{
	/* data */
	int					old_stdin;
	int					old_stdout;

}	t_global;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}	t_env;

enum	e_token_type
{
	UNKNOWN,
	OR,
	AND,
	PIPE,
	PARENS,
	CMD,
	OPTION,
	DB_QUOTE,
	SM_QUOTE,
	RDIR_STDIN,
	RDIR_STDOUT,
	RDIR_STDAPD,
	HERE_DOC
};

typedef struct s_token
{
	enum e_token_type	type;
	int					hd_num;
	char				*content;
	struct s_token		*next;
}	t_token;

typedef struct s_tree_node
{
	int					*type;
	t_token				*tokens;
	t_token				*command;
	t_token				*redir;
	struct s_tree_node *left;
	struct s_tree_node *right;
}	t_tree_node;

#endif