#include "../../inc/minishell.h"

static int	ft_checkname(char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (0);
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_addvar(char **spl, int haseq)
{
	t_env	*tmp;

	tmp = ft_calloc(1, sizeof(t_env));
	tmp->name = ft_strdup(spl[0]);
	if (spl[1])
	{
		tmp->value = ft_strdup(spl[1]);
		tmp->def = 1;
	}
	else if (!spl[1] && haseq)
	{
		tmp->value = ft_strdup("");
		tmp->def = 1;
	}
	else
	{
		tmp->value = ft_strdup("");
		tmp->def = 0;
	}
	ft_lstadd_back_env(&g_sh.env, tmp);
}

void	ft_printexport(t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->name, "_", 2))
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(env->name, STDOUT_FILENO);
			if (env->def)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(env->value, STDOUT_FILENO);
				ft_putstr_fd("\"", STDOUT_FILENO);
			}
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		env = env->next;
	}
}

static void	ex_help(char **spl, char **args, int haseq, int *i)
{
	if (!ft_checkname(spl[0]) || args[*i][0] == '=')
		ft_error(1, "Incorrect variable name", 0);
	else if (!ft_strcmp(spl[0], "_"))
		*i = *i + 0;
	else if (ft_edit_env(&g_sh.env, spl[0], spl[1], haseq) == 0)
		ft_addvar(spl, haseq);
}

void	ft_export(char **args)
{
	char	**spl;
	int		i;
	int		haseq;

	i = 0;
	if (!args[1])
		ft_sortlist_env(args, &g_sh.env);
	while (args[++i])
	{
		haseq = 0;
		if (args[i][0] == '=')
			ft_error(1, "Incorrect variable name", 0);
		else
		{
			if (ft_strchr(args[i], '='))
				haseq = 1;
			spl = ft_split(args[i], '=');
			ex_help(spl, args, haseq, &i);
			ft_freetab(spl);
		}
	}
}
