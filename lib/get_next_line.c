#include "libft.h"

static char	*ft_strini(size_t size)
{
	char			*str;
	int				len;
	int				i;

	i = 0;
	len = (sizeof(char) * (size + 1));
	str = malloc(len);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

static int	ft_free(char **str, int ret)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}

static char	*ft_temp_stl(char *stl, char *cpy, int b, int i)
{
	char		*tmp;
	int			len;

	if (i == 1)
		tmp = ft_strjoin(stl, cpy);
	if (i == 2)
	{
		if (b > 0)
			len = ft_strlen(cpy) + 1;
		else
			len = ft_strlen(cpy);
		tmp = ft_strdup(stl + len);
	}
	ft_free(&stl, 0);
	stl = tmp;
	return (stl);
}

static char	get_to_find(ssize_t b)
{
	if (b == 0)
		return ('\0');
	return ('\n');
}

int	get_next_line(int fd, char **line)
{
	ssize_t		b;
	char		buf[BUFFER_SIZE + 1];
	static char	*stl;
	char		to_find;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (stl == NULL)
		stl = ft_strini(0);
	b = 1;
	while (!ft_strchr(stl, '\n') && b > 0)
	{
		b = read(fd, buf, BUFFER_SIZE);
		buf[b] = '\0';
		stl = ft_temp_stl(stl, buf, b, 1);
	}
	to_find = get_to_find(b);
	if (b >= 0)
		*line = ft_substr(stl, 0, (ft_strchr(stl, to_find) - stl));
	else
		return (ft_free(&stl, -1));
	stl = ft_temp_stl(stl, *line, b, 2);
	if (b == 0)
		return (ft_free(&stl, 0));
	return (1);
}
