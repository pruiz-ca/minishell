#include "minishell.h"

void	ft_lstadd_back_env(t_env **env, t_env *new)
{
	t_env	*tmp;

	if (!env || !new)
		return ;
	if (*env == NULL)
		*env = new;
	else
	{
		tmp = *env;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
}

void	ft_lstadd_front_env(t_env **env, t_env *new)
{
	new->next = *env;
	*env = new;
}

void	ft_lstinsert_sorted(t_env **clone, t_env *new)
{
	t_env	*iter;

	iter = *clone;
	if (!iter || ft_strcmp(new->name, iter->name) < 0)
		ft_lstadd_front_env(clone, new);
	else
	{
		while (iter && iter->next)
		{
			if (ft_strcmp(new->name, iter->name) > 0
				&& ft_strcmp(new->name, iter->next->name) < 0)
			{
				new->next = iter->next;
				iter->next = new;
				return ;
			}
			iter = iter->next;
		}
		ft_lstadd_back_env(&iter, new);
	}
}

void	ft_sortlist_env(char **args, t_env **env)
{
	t_env	*iter;
	t_env	*tmp;
	t_env	*clone;

	iter = *env;
	clone = NULL;
	(void)args;
	while (iter)
	{
		tmp = malloc(sizeof(t_env));
		tmp->name = ft_strdup(iter->name);
		if (iter->value)
			tmp->value = ft_strdup(iter->value);
		else
			tmp->value = NULL;
		tmp->next = NULL;
		tmp->def = iter->def;
		ft_lstinsert_sorted(&clone, tmp);
		iter = iter->next;
	}
	ft_printexport(clone);
	ft_freeclone(clone);
}
