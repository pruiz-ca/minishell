#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst > src)
		while (len-- > 0)
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
	else
		while (i++ < len)
			((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
