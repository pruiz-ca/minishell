#include "libft.h"

int	ft_ternary(int cond, int true_val, int false_val)
{
	if (cond)
		return (true_val);
	return (false_val);
}
