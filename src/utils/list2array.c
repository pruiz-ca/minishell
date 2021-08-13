#include "../../inc/minishell.h"

static int	ft_getlistlen(t_env *env)
{
	t_env	*tmp;
	int		cont;

	cont = 0;
	tmp = env;
	while (tmp)
	{
		cont++;
		tmp = tmp->next;
	}
	return (cont);
}

char	**ft_list2array(t_env *env)
{
	char	**new;
	t_env	*iter;
	char	*tmp[2];
	int		i;

	i = 0;
	new = ft_calloc(ft_getlistlen(env) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	iter = env;
	while (iter)
	{
		tmp[0] = ft_strjoin(iter->name, "=");
		tmp[1] = ft_strjoin(tmp[0], iter->value);
		new[i] = ft_strdup(tmp[1]);
		if (tmp[0])
			free(tmp[0]);
		if (tmp[1])
			free(tmp[1]);
		i++;
		iter = iter->next;
	}
	return (new);
}
