#include "libft.h"

char	*ft_strdup_limit(const char *src, int end)
{
	char	*p;
	int		i;

	p = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i] && i < end)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
