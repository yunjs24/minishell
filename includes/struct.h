

typedef struct s_global
{
	/* data */
}	t_global;


typedef struct s_token 
{
	char	*content;
}	t_token;

typedef struct s_tree_node
{
	int				*type;
	t_token			*tokens;
	t_token			*command;
	t_token			*redir;
	struct s_tree_node *left;
	struct s_tree_node *right;
}	t_tree_node;
