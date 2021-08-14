#include "minishell.h"

t_token	*init_lexer(t_lexer **lex, char *s)
{
	t_token	*tok;

	(*lex) = malloc(sizeof(t_lexer));
	(*lex)->state = S_NRL;
	(*lex)->esc = 0;
	(*lex)->cb = 0;
	(*lex)->tok = ft_calloc(1, sizeof(t_token));
	(*lex)->s = ft_strtrim(s, " ");
	tok = (*lex)->tok;
	tok->data = ft_calloc(1, sizeof(char));
	tok->tkn = C_NULL;
	tok->next = NULL;
	return (tok);
}

int	lexer(char *s, t_lexer **lex)
{
	int		i;
	t_token	*tok;

	i = 0;
	if (!s)
		return (0);
	tok = init_lexer(lex, s);
	while ((*lex)->s[i] != '\0')
	{
		if ((*lex)->state == S_NRL)
			nrml_state(&i, &tok, lex);
		else if ((*lex)->state == S_DQ)
			double_quotes(&i, &tok, lex);
		else if ((*lex)->state == S_SQ)
			simple_quotes((*lex)->s[i], &tok, lex);
		i++;
	}
	return (1);
}
