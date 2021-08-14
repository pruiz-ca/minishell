#include "minishell.h"

char	*get_line(void)
{
	char	*tmp;
	char	*line;
	char	*pr;
	int		tmp2;

	tmp2 = errno;
	pr = prompt();
	tmp = readline(pr);
	if (!tmp)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	errno = tmp2;
	line = reconstruct(tmp);
	if (line && *line)
		add_history(line);
	free(tmp);
	free(pr);
	return (line);
}
