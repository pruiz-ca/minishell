#include "../../inc/minishell.h"

static void	free_bin(char **ar, char *f1, char *f2, char **ar2)
{
	int		i;

	i = -1;
	if (ar)
		ft_freetab(ar);
	if (f1)
		free(f1);
	if (f2)
		free(f2);
	if (ar2)
		while (ar2[++i])
			free(ar2[i]);
}

static char	**path_exists(void)
{
	char	**searchfolder;

	searchfolder = NULL;
	if (!ft_getenv("PATH"))
		ft_error(127, "No such file or directory", 0);
	else
		searchfolder = ft_split(ft_getenv("PATH"), ':');
	return (searchfolder);
}

char	*ft_findbinaries(char **args)
{
	char	**searchfolder;
	char	*searchfile[2];
	int		i;

	i = -1;
	if (ft_fileexists(args[0]))
		return (args[0]);
	searchfolder = path_exists();
	if (!searchfolder)
		return (NULL);
	while (searchfolder[++i])
	{
		searchfile[0] = ft_strjoin(searchfolder[i], "/");
		searchfile[1] = ft_strjoin(searchfile[0], args[0]);
		if (ft_fileexists(searchfile[1]))
		{
			free_bin(searchfolder, searchfile[0], args[0], NULL);
			errno = 0;
			return (searchfile[1]);
		}
		free_bin(NULL, searchfile[0], searchfile[1], NULL);
	}
	free_bin(searchfolder, NULL, NULL, args);
	ft_error(127, "Command not found", 0);
	return (NULL);
}

void	ft_hub(char **args, int forked)
{
	if (!args)
		return ;
	if (ft_strlen(args[0]) == 3 && !ft_strncmp(args[0], "pwd", 3))
		ft_pwd();
	else if (ft_strlen(args[0]) == 2 && !ft_strncmp(args[0], "cd", 2))
		ft_cd(args);
	else if (ft_strlen(args[0]) == 4 && !ft_strncmp(args[0], "echo", 4))
		ft_echo(args);
	else if (ft_strlen(args[0]) == 3 && !ft_strncmp(args[0], "env", 3))
		ft_env(args, g_sh.env);
	else if (ft_strlen(args[0]) == 6 && !ft_strncmp(args[0], "export", 6))
		ft_export(args);
	else if (ft_strlen(args[0]) == 5 && !ft_strncmp(args[0], "unset", 5))
		ft_unset(args);
	else if (ft_strlen(args[0]) == 4 && !ft_strncmp(args[0], "exit", 4))
		ft_exit(args);
	else
		ft_error(127, "Command not found", 0);
	if (forked == 1)
		exit(0);
}
