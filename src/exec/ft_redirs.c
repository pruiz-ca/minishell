#include "minishell.h"

static int	ft_redir_in(t_io *tmp, int inb)
{
	int	fd;

	fd = open(tmp->name, O_RDONLY);
	if (fd < 0)
	{
		if (inb == 1)
			ft_error(1, "No such file or directory\n", inb);
		ft_error(1, "No such file or directory", inb);
		return (0);
	}
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		return (1);
	}
}

static int	ft_redir_out(t_io *tmp)
{
	int	fd;

	if (tmp->is_app == 1)
		fd = open(tmp->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(tmp->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (0);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

int	ft_redir(t_io *io, int inb)
{
	t_io	*tmp;
	int		status;

	tmp = io;
	status = 1;
	while (tmp)
	{
		if (tmp->is_out == 0 && tmp->is_app == 0)
			status = ft_redir_in(tmp, inb);
		else if (tmp->is_out == 1)
			ft_redir_out(tmp);
		else
			ft_error(127, "Redirection is nonsense", 0);
		tmp = tmp->next;
	}
	return (status);
}
