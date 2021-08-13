#include "../../inc/minishell.h"

void	ft_freecmd(t_cmdito *cmd)
{
	t_cmdito	*tmp;

	while (cmd)
	{
		tmp = cmd;
		if (!cmd->freed && cmd->args)
			ft_freetab(cmd->args);
		if (cmd->io)
			ft_freeio(&cmd->io);
		cmd = cmd->next;
		free(tmp);
	}
	free(cmd);
}

void	ft_freelex(t_token **lst, int flag)
{
	t_token	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->data && flag == 1)
			free((*lst)->data);
		free(*lst);
		*lst = tmp;
	}
}

void	ft_freeio(t_io **lst)
{
	t_io	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->name);
		free(*lst);
		*lst = tmp;
	}
}

void	ft_freemain(char **tabs, char *line)
{
	if (tabs)
		ft_freetab(tabs);
	free(line);
}

void	ft_freeclone(t_env *clone)
{
	t_env	*tmp;

	while (clone)
	{
		tmp = clone->next;
		if (clone->name)
			free(clone->name);
		if (clone->value)
			free(clone->value);
		free(clone);
		clone = tmp;
	}
	free(clone);
}
