#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	p = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
