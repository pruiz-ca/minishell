#include "minishell.h"

void	ft_unset(char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		if (ft_strcmp(args[i], "_"))
			ft_delenv(&g_sh.env, args[i]);
		i++;
	}
}
