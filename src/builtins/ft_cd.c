#include "../../inc/minishell.h"

static void	ft_getdirs(char **args, char **old_dir, char **new_dir)
{
	char		*tmp;

	*old_dir = getcwd(NULL, 0);
	if (!args[1])
		*new_dir = ft_getenv("HOME");
	else if (args[1][0] == '~')
	{
		tmp = ft_getenv("HOME");
		*new_dir = ft_strjoin(tmp, args[1] + 1);
	}
	else if (args[1][0] == '-' && ft_getenv("OLDPWD"))
		*new_dir = ft_strdup(ft_getenv("OLDPWD"));
	else
		*new_dir = ft_strdup(args[1]);
}

void	ft_cd(char **args)
{
	char		*old_dir;
	char		*new_dir;
	int			error;

	ft_getdirs(args, &old_dir, &new_dir);
	error = chdir(new_dir);
	if (new_dir)
		free(new_dir);
	new_dir = getcwd(NULL, 0);
	if (error == -1)
		ft_error(errno, strerror(errno), 0);
	else
	{
		ft_edit_env(&g_sh.env, "OLDPWD", old_dir, 1);
		ft_edit_env(&g_sh.env, "PWD", new_dir, 1);
	}
	free(new_dir);
	free(old_dir);
}
