#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static int	ft_int_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	len = ft_int_count(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[len] = '\0';
	while (len-- > i)
	{
		str[len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
