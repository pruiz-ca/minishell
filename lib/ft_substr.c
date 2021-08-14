#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	s_size;

	if (!s)
		return (0);
	i = -1;
	s_size = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(*s) * len + 1);
	if (!str)
		return (NULL);
	while (++i < len && start < s_size)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
