#include "../../inc/minishell.h"

static int	check_sec(t_token *tmp)
{
	while (tmp->next)
	{
		if (tmp->tkn == tmp->next->tkn && tmp->tkn != WORD
			&& printf("%s`%c'\n", SYNTAX_E, tmp->tkn))
			return (0);
		tmp = tmp->next;
	}
	if (tmp->tkn != WORD && tmp->tkn != C_NULL && tmp->tkn != C_SC
		&& tmp->tkn != C_AM && printf("%s`newline'\n", SYNTAX_E))
		return (0);
	if (!ft_strncmp(tmp->data, "", 2))
		return (0);
	return (1);
}

int	check_syntax(const t_lexer *lex)
{
	t_token	*tmp;

	if (lex->esc == 1 && printf("%s`newline'\n", SYNTAX_E))
		return (0);
	if ((lex->state == S_SQ || lex->state == S_DQ)
		&& printf("%s\n", QUOTE_E))
		return (0);
	if ((lex->cb == 1)
		&& printf("%s\n", CURLY_E))
		return (0);
	tmp = lex->tok;
	if (!ft_strncmp(tmp->data, ";", 2) && printf("%s`%c'\n", SYNTAX_E, ';'))
		return (0);
	if ((tmp->tkn == C_PI || tmp->tkn == C_AM || tmp->tkn == C_SC)
		&& printf("%s`%c'\n", SYNTAX_E, tmp->tkn))
		return (0);
	if (!check_sec(tmp))
		return (0);
	return (1);
}

void	ft_errormsg(char *errormsg)
{
	write(1, errormsg, ft_strlen(errormsg));
}

void	ft_error(int errornum, char *errormsg, int bye)
{
	write(1, "minishell: ", 11);
	write(1, errormsg, ft_strlen(errormsg));
	errno = errornum;
	if (bye == 1)
		exit(errornum);
	write(1, "\n", 1);
}
