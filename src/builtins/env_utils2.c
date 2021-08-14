#include "minishell.h"

static void	init_helper(char **split, t_env **tmp)
{
	if (split[1])
	{
		(*tmp)->def = 1;
		(*tmp)->value = ft_strdup(split[1]);
	}
	else
	{
		(*tmp)->def = 0;
		(*tmp)->value = "";
	}
}

void	ft_initenv_list(char **envp, t_env **env)
{
	char	**split;
	char	**oldpwd;
	t_env	*tmp;
	int		i;

	i = 0;
	oldpwd = ft_split("export OLDPWD", ' ');
	*env = NULL;
	while (envp[i])
	{
		split = ft_split(envp[i], '=');
		tmp = malloc(sizeof(t_env));
		tmp->name = ft_strdup(split[0]);
		init_helper(split, &tmp);
		ft_freetab(split);
		tmp->next = NULL;
		ft_lstadd_back_env(env, tmp);
		i++;
	}
	ft_export(oldpwd);
	ft_freetab(oldpwd);
}

static char	*edit_help(t_env **tmp, int haseq, char *newvalue)
{
	char	*new;

	if (!newvalue && !haseq)
	{
		if ((*tmp)->def == 0)
			(*tmp)->def = 0;
		new = ft_strdup((*tmp)->value);
	}
	else
	{
		(*tmp)->def = 1;
		if (!newvalue && haseq)
			new = ft_strdup("");
		else
			new = ft_strdup(newvalue);
	}
	return (new);
}

int	ft_edit_env(t_env **env, char *name, char *newvalue, int haseq)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_strlen(name) + 1))
		{
			newvalue = edit_help(&tmp, haseq, newvalue);
			if (tmp->value)
				free(tmp->value);
			tmp->value = ft_strdup(newvalue);
			free(newvalue);
			return (1);
		}
		else
			tmp = tmp->next;
	}
	return (0);
}
