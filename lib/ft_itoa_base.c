#include "libft.h"

static unsigned long	ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static int	ft_int_count(int n, int base)
{
	int				i;
	unsigned int	u;
	unsigned int	ubase;

	i = 1;
	ubase = (unsigned int)base;
	u = n;
	while ((u >= ubase) > 0)
	{
		u /= ubase;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int n, unsigned long base)
{
	char			*str;
	int				len;
	int				i;
	unsigned int	u;

	len = ft_int_count(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	u = n;
	str[len] = '\0';
	while (len > i)
	{
		if (u % base < 10)
			str[--len] = ft_abs(u % base) + '0';
		else
			str[--len] = ft_abs(u % base) - 10 + 'a';
		u /= base;
	}
	return (str);
}
