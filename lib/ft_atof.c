#include "libft.h"

double	ft_atof(const char *str)
{
	double		sign;
	double		num;
	int			dot;
	int			i;

	sign = 1;
	dot = 0;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
			dot = i;
		else
			num = (num * 10) + str[i] - '0';
		i++;
	}
	if (dot > 0)
		num = num / ft_power(10, i - dot - 1);
	return (sign * num);
}
