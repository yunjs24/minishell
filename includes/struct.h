#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_global
{
	/* data */
}	t_global;

enum	e_token_type
{
	UNKNOWN,
	CMD,
	OPTION,
	PIPE,
	OR,
	AND
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