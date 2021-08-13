#include "../../inc/minishell.h"

char	**append_arg(char *line, char **ar, int *n)
{
	char	**args;
	int		i;

	i = 0;
	if (!ar)
		args = ft_calloc(2, sizeof(char *));
	else
		args = ft_calloc(*n + 2, sizeof(char *));
	while (ar && ar[i])
	{
		args[i] = ar[i];
		i++;
	}
	args[i] = ft_strdup(line);
	args[i + 1] = NULL;
	free(line);
	free(ar);
	(*n)++;
	return (args);
}

void	deal_redir(t_lexer *lex, t_cmdito **cmd)
{
	char	*tmp;

	if (lex->tok->tkn != C_LTLT)
	{
		tmp = lex->tok->next->data;
		lex->tok->next->data = ft_strtrim(tmp, "'\"");
		free(tmp);
	}
	if (lex->tok->tkn == C_GT)
		add_redir(&(*cmd)->io, new_io(lex->tok->next->data, 0, 1));
	else if (lex->tok->tkn == C_GTGT)
		add_redir(&(*cmd)->io, new_io(lex->tok->next->data, 1, 1));
	else if (lex->tok->tkn == C_LT)
		add_redir(&(*cmd)->io, new_io(lex->tok->next->data, 0, 0));
	else if (lex->tok->tkn == C_LTLT)
		read_heredoc(cmd, lex->tok->next->data);
	if (lex->tok)
		free(lex->tok->data);
	if (lex->tok->next)
		lex->tok = lex->tok->next;
}
