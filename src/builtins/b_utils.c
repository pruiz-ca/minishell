#include "minishell.h"

int	ft_isdigit_str(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_word_count(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_fileexists(char *file)
{
	int			fd;
	struct stat	st;

	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		fstat(fd, &st);
		if (S_ISDIR(st.st_mode))
			return (0);
		close(fd);
		return (1);
	}
	return (0);
}

int	ft_isbuiltin(char **args)
{
	if (ft_strlen(args[0]) == 3 && !ft_strncmp(args[0], "pwd", 3))
		return (1);
	else if (ft_strlen(args[0]) == 2 && !ft_strncmp(args[0], "cd", 2))
		return (1);
	else if (ft_strlen(args[0]) == 4 && !ft_strncmp(args[0], "echo", 4))
		return (1);
	else if (ft_strlen(args[0]) == 3 && !ft_strncmp(args[0], "env", 3))
		return (1);
	else if (ft_strlen(args[0]) == 6 && !ft_strncmp(args[0], "export", 6))
		return (1);
	else if (ft_strlen(args[0]) == 5 && !ft_strncmp(args[0], "unset", 5))
		return (1);
	else if (ft_strlen(args[0]) == 4 && !ft_strncmp(args[0], "exit", 4))
		return (1);
	else
		return (0);
}
