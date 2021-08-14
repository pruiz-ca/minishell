#include "libft.h"

void	ft_freetab(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		if (tabs[i])
		{
			free(tabs[i]);
			tabs[i] = NULL;
		}
		i++;
	}
	free(tabs);
	tabs = NULL;
}
