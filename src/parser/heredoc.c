#include "../../inc/minishell.h"

static void	process_herestring(char *line, int fd, const char *del)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	if (ft_strchr(del, '"') || ft_strchr(del, '"'))
		write(fd, line, ft_strlen(line));
	else
	{
		while (line[++i])
		{
			if (line[i] == '$')
			{
				j = get_len(line, i + 1);
				new = get_val(line, i, j);
				write(fd, new, ft_strlen(new));
				i += j;
			}
			else
				write(fd, &line[i], 1);
		}
	}
	write(fd, "\n", 1);
	free(line);
}

static char	*get_file(void)
{
	char		*file;
	char		*tmp[2];
	struct stat	buf;
	int			i;

	i = 0;
	while (++i)
	{
		tmp[0] = ft_strdup(".tmp");
		tmp[1] = ft_itoa(i);
		file = ft_strjoin(tmp[0], tmp[1]);
		if (stat(file, &buf) == -1)
		{
			free(tmp[0]);
			free(tmp[1]);
			return (file);
		}
		free(file);
		free(tmp[0]);
		free(tmp[1]);
	}
	return (NULL);
}

void	read_heredoc(t_cmdito **cmd, char *del)
{
	const char	*delim = del;
	char		*line;
	char		*file;
	int			fd;

	file = get_file();
	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	while (1)
	{
		write(1, "> ", 2);
		get_next_line(0, &line);
		if (!ft_strncmp(line, delim, ft_strlen(delim) + 1))
			break ;
		process_herestring(line, fd, delim);
	}
	free(line);
	free(del);
	close(fd);
	add_redir(&(*cmd)->io, new_io(file, 0, 0));
}
