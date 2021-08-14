#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *)dst;
	i = 0;
	if (dst == NULL && src == NULL && n)
		return (dst);
	while (i < (int)n)
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
