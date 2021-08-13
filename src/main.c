#include "../inc/minishell.h"
t_shell	g_sh;

static void	init_minishell(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	intro();
	ft_initenv_list(envp, &g_sh.env);
	dup2(STDIN_FILENO, g_sh.fd_bak[0]);
	dup2(STDOUT_FILENO, g_sh.fd_bak[1]);
}

static void	signals(void)
{
	signal(SIGINT, sig_main);
	signal(SIGQUIT, SIG_IGN);
}

void	init_fds(void)
{
	dup2(g_sh.fd_bak[0], STDIN_FILENO);
	dup2(g_sh.fd_bak[1], STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**tabs;
	int		i;

	init_minishell(argc, argv, envp);
	while (1)
	{
		signals();
		line = get_line();
		if (!line)
			continue ;
		tabs = ft_split(line, ';');
		i = -1;
		while (tabs[++i])
		{
			if (!lex_parse(tabs[i]))
				continue ;
			errno = 0;
			ft_execute(g_sh.cmd);
			ft_freecmd(g_sh.cmd);
			init_fds();
		}
		ft_freemain(tabs, line);
	}
	return (0);
}
