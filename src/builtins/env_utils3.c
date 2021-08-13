#include "../../inc/minishell.h"

char	*ft_getenv(char *name)
{
	t_env	*tmp;

	tmp = g_sh.env;
	while (tmp)
	{
		if (!ft_strncmp(name, tmp->name, ft_strlen(tmp->name) + 1))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	reconnect(t_env **env, char *name)
{
	t_env	*iter_tmp;
	t_env	*tmp;

	iter_tmp = *env;
	while (iter_tmp && iter_tmp->next)
	{
		if (!ft_strcmp(iter_tmp->next->name, name))
		{
			tmp = iter_tmp->next;
			iter_tmp->next = iter_tmp->next->next;
			if (tmp->name)
				free(tmp->name);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
		}
		iter_tmp = iter_tmp->next;
	}
}

void	ft_delenv(t_env **env, char *name)
{
	t_env	*tmp;

	while (!ft_strcmp((*env)->name, name))
	{
		tmp = *env;
		*env = (*env)->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	reconnect(env, name);
}
