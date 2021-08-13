#include "libft.h"

char	*ft_strupper(char *str)
{
	char	*ref;

	ref = str;
	while (*str != '\0')
	{
		if (*str >= 97 && *str <= 122)
			*str -= 32;
		str++;
	}
	return (ref);
}
