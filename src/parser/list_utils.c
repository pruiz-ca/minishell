#include "minishell.h"

t_cmdito	*init_cmd(void)
{
	t_cmdito	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmdito));
	if (!cmd)
		exit(0);
	cmd->n_ar = 0;
	cmd->next = NULL;
	cmd->freed = 0;
	return (cmd);
}

void	add_cmd(t_cmdito **lst, t_cmdito *add)
{
	t_cmdito	*tmp;

	if (!*lst)
		*lst = add;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = add;
	}
}

void	add_redir(t_io **lst, t_io *new)
{
	t_io	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
}

t_io	*new_io(char *name, int is_app, int is_out)
{
	t_io	*new;

	new = ft_calloc(1, sizeof(t_io));
	new->next = NULL;
	new->name = name;
	new->is_app = is_app;
	new->is_out = is_out;
	return (new);
}
