#include "minishell.h"

int	get_type(char c)
{
	const char				c_ty[12] = {'|', '\'', '"', ';', ' ',
		'>', '<', '&', '\\', '$', -44, '\0'};
	const enum e_chrtype	e_ty[12] = {C_PI, C_SQ, C_DQ,
			C_SC, C_SP, C_GT, C_LT, C_AM, C_BL, C_DL, C_HD_SC, C_NULL};
	int						i;

	i = -1;
	while (c_ty[++i])
		if (c == c_ty[i])
			return (e_ty[i]);
	return (C_NRL);
}

char	*ft_strchjoin(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * i + 2);
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return (new);
}

void	deal_char(t_token *tok, char c, int nstat, t_lexer **lex)
{
	tok->data = ft_strchjoin(tok->data, c);
	tok->tkn = WORD;
	if ((*lex)->esc == 1)
		(*lex)->esc = 0;
	(*lex)->state = nstat;
}

void	new_token(t_token **tok)
{
	int	i;

	i = ft_strlen((*tok)->data);
	if (i > 0)
	{
		(*tok)->data[i] = '\0';
		(*tok)->next = ft_calloc(1, sizeof(t_token));
		(*tok) = (*tok)->next;
		(*tok)->tkn = C_NULL;
		(*tok)->data = ft_calloc(1, sizeof(char));
	}
}
