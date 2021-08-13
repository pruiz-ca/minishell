#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*usdst;
	unsigned char	*ussrc;
	int				i;

	usdst = (unsigned char *)dst;
	ussrc = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		usdst[i] = ussrc[i];
		if (ussrc[i] == (unsigned char)c)
			return (&usdst[i + 1]);
		i++;
	}
	return (NULL);
}
