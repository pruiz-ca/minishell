#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	while (*src)
	{
		if (len < dstsize)
		{
			if (i == dstsize - 1)
				*dst = '\0';
			else
				*dst = *src;
			i++;
		}
		src++;
		dst++;
		len++;
	}
	if (dstsize == 0 || len > dstsize)
		return (len);
	*dst = '\0';
	return (i);
}
