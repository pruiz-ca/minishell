#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign >= 2147483647)
			return (2147483647);
		else if (num * sign <= -2147483648)
			return (-2147483648);
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (sign * num);
}
