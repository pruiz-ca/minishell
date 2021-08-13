#include "../../inc/minishell.h"

void	nrml_st_2(char *s, int *i, t_token **tok)
{
	const int	c_ty = get_type(s[*i]);

	if (c_ty == C_PI || c_ty == C_SC || c_ty == C_GT
		|| c_ty == C_LT || c_ty == C_AM)
	{
		new_token(tok);
		(*tok)->data = ft_strchjoin((*tok)->data, c_ty);
		if (s[*i + 1] && get_type(s[*i + 1]) == c_ty
			&& (c_ty == C_GT || c_ty == C_LT))
		{
			(*tok)->data = ft_strchjoin((*tok)->data, c_ty);
			(*tok)->tkn = ft_ternary(c_ty == C_GT, C_GTGT, C_LTLT);
			(*i)++;
		}
		else
			(*tok)->tkn = c_ty;
		if (s[*i + 1] != '\0')
			new_token(tok);
	}	
}

void	nrml_state(int *i, t_token **tok, t_lexer **lex)
{
	const int	c_ty = get_type((*lex)->s[*i]);

	if (c_ty == C_BL)
		(*lex)->esc = 1;
	else if (((*lex)->esc && c_ty == C_HD_SC) || c_ty == C_SC)
		deal_char(*tok, C_SC, (*lex)->state, lex);
	else if ((*lex)->cb && (*lex)->s[*i] == '}')
		(*lex)->cb = 0;
	else if ((*lex)->esc || c_ty == C_NRL)
		deal_char(*tok, (*lex)->s[*i], (*lex)->state, lex);
	else if (c_ty == C_DQ || c_ty == C_SQ)
		(*lex)->state = ft_ternary(c_ty == C_DQ, S_DQ, S_SQ);
	else if (c_ty == C_SP)
		new_token(tok);
	else if (c_ty == C_DL && !(*lex)->esc)
		*i = expand_env(lex, *i, tok);
	else if (c_ty == C_DL)
		deal_char(*tok, (*lex)->s[*i], S_NRL, lex);
	else
		nrml_st_2((*lex)->s, i, tok);
}

void	double_quotes(int *i, t_token **tok, t_lexer **lex)
{
	const int	c_ty = get_type((*lex)->s[*i]);

	if (c_ty == C_HD_SC)
		(*tok)->data = ft_strchjoin((*tok)->data, C_SC);
	else if (c_ty == C_DL && get_type((*lex)->s[*i - 1]) != C_BL)
		*i = expand_env(lex, *i, tok);
	else if (c_ty != C_BL && c_ty != C_DQ)
		(*tok)->data = ft_strchjoin((*tok)->data, (*lex)->s[*i]);
	if (c_ty == C_DQ && get_type((*lex)->s[*i - 1]) != C_BL)
		(*lex)->state = S_NRL;
	(*tok)->tkn = WORD;
}

void	simple_quotes(char c, t_token **tok, t_lexer **lex)
{
	const int	c_ty = get_type(c);

	if (c_ty == C_HD_SC)
		(*tok)->data = ft_strchjoin((*tok)->data, C_SC);
	else if (c_ty != C_SQ)
		(*tok)->data = ft_strchjoin((*tok)->data, c);
	if (c_ty == C_SQ)
		(*lex)->state = S_NRL;
	(*tok)->tkn = WORD;
}
