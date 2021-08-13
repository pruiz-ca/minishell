#include "libft.h"

void	ft_swap_double(double *s1, double *s2)
{
	double	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
