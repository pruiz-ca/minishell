#include "minishell.h"

void	ft_exit(char **args)
{
	int		value;

	ft_putstr_fd("exit\n", 1);
	if (!args[1])
		exit (0);
	if (ft_isdigit_str(args[1]) && ft_word_count(args) == 2)
	{
		value = ft_atoi(args[1]);
		while (value > 255)
			value -= 256;
		while (value < 0)
			value += 256;
		exit(ft_atoi(args[1]));
	}
	if (!ft_isdigit_str(args[1]))
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 1);
		exit (255);
	}
	if (ft_word_count(args) > 2)
		ft_putstr_fd("minishell: exit: too many arguments\n", 1);
}
