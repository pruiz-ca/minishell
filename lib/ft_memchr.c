#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n > 0)
	{
		if (*(char *)str == (char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
