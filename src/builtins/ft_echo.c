#include "minishell.h"

void	ft_echo(char **args)
{
	int		i;
	bool	flag;

	flag = 0;
	i = 0;
	while (args[++i] && !ft_strncmp(args[i], "-n", 3))
		flag = 1;
	while (args[i])
	{
		ft_putstr_fd(args[i++], STDOUT_FILENO);
		if (i < ft_word_count(args))
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
