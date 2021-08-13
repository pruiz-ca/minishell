#include "libft.h"

static unsigned long	ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static size_t	ft_int_count(unsigned long n, unsigned long base)
{
	size_t	i;

	i = 1;
	while ((n >= base) > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_llu(unsigned long n, unsigned long base)
{
	char	*str;
	int		len;

	len = ft_int_count(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		if (n % base < 10)
			str[--len] = ft_abs(n % base) + '0';
		else
			str[--len] = ft_abs(n % base) - 10 + 'a';
		n /= base;
	}
	return (str);
}
