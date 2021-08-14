#include "minishell.h"

void	ft_exchild(t_cmdito *tmp, int fd[2], int old_fd[2])
{
	int	check;

	if (tmp->next)
	{
		close(fd[READ]);
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
	}
	if (old_fd[WRITE] != -1)
	{
		close(old_fd[WRITE]);
		dup2(old_fd[READ], STDIN_FILENO);
		close(old_fd[READ]);
	}
	check = ft_redir(tmp->io, 1);
	if (ft_isbuiltin(tmp->args) == 1 && check)
		ft_hub(tmp->args, 1);
	else
	{
		signal(SIGINT, sig_fork);
		signal(SIGQUIT, sig_fork);
		execve(tmp->args[0], tmp->args, ft_list2array(g_sh.env));
	}
}

void	ft_exparent(int fd[2], int old_fd[2], int i, int islast)
{
	signal(SIGINT, sig_fork);
	signal(SIGQUIT, sig_fork);
	if (i > 0)
		close(old_fd[READ]);
	old_fd[READ] = fd[READ];
	old_fd[WRITE] = fd[WRITE];
	close(fd[WRITE]);
	if (islast)
		close(fd[READ]);
}

void	ft_cmds(t_cmdito *tmp, int old_fd[2], int *i, int islast)
{
	int		fd[2];

	if (ft_isbuiltin(tmp->args) && !g_sh.hasp)
	{
		if (ft_redir(tmp->io, 0))
			ft_hub(tmp->args, 0);
	}
	else
	{
		if (pipe(fd) == -1)
			ft_error(127, "Pipe error\n", 0);
		if (!strncmp(tmp->args[0], "exit", 4) && g_sh.hasp)
		{
			ft_exparent(fd, old_fd, *i, islast);
			return ;
		}
		tmp->pid = fork();
		if (tmp->pid < 0)
			ft_error(errno, strerror(errno), 0);
		else if (tmp->pid == 0)
			ft_exchild(tmp, fd, old_fd);
		else
			ft_exparent(fd, old_fd, *i, islast);
		(*i)++;
	}
}

static void	get_errno(int i)
{
	int		ex;
	int		status;

	while (i-- > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			ex = WEXITSTATUS(status);
			errno = ex;
		}
	}
}

void	ft_execute(t_cmdito *cmd)
{
	int			i;
	int			islast;
	int			old_fd[2];
	t_cmdito	*tmp;

	i = 0;
	tmp = cmd;
	old_fd[READ] = STDIN_FILENO;
	old_fd[WRITE] = -1;
	while (tmp)
	{
		islast = 0;
		if (!tmp->next)
			islast = 1;
		if (tmp->args)
		{
			init_fds();
			if (!ft_isbuiltin(tmp->args))
				tmp->args[0] = ft_findbinaries(tmp->args);
			if (tmp->args[0])
				ft_cmds(tmp, old_fd, &i, islast);
		}
		tmp = tmp->next;
	}
	get_errno(i);
}
