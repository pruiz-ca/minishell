#include "minishell.h"

void	ft_env(char **args, t_env *env)
{
	if (args[1])
	{
		ft_error(127, "No such file or directory", 0);
		return ;
	}
	while (env)
	{
		if (env->value && ft_strcmp(env->value, ""))
		{
			ft_putstr_fd(env->name, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(env->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		env = env->next;
	}
}
