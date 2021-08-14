#include "libft.h"

static int	ft_string_count(char const *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[j] && ft_isspace(s[j]) == 0)
		i = 1;
	while (s[j])
	{
		if (ft_isspace(s[j]) == 1 && ft_isspace(s[j + 1]) == 0 && s[j + 1])
			i++;
		j++;
	}
	return (i);
}

static char	*ft_get_split(char const *str, int start)
{
	int		i;
	int		end;
	char	*segment;

	while (ft_isspace(str[start]) == 1 && str[start])
		start++;
	end = start;
	while (ft_isspace(str[end]) == 0 && str[end])
		end++;
	segment = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!segment)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		segment[i] = str[start + i];
		i++;
	}
	segment[i] = '\0';
	return (segment);
}

char	**ft_split_isspace(char const *s, int *n_words)
{
	char	**tab;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	*n_words = ft_string_count(s);
	tab = (char **)malloc(sizeof(char *) * (*n_words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	start = 0;
	while (ft_isspace(s[start]))
		start++;
	while (i < *n_words)
	{
		tab[i] = ft_get_split(s, start);
		while (ft_isspace(s[start]) == 1)
			start++;
		start += ft_strlen(tab[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
