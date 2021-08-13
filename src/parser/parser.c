#include "../../inc/minishell.h"

void	build_commands(t_lexer *lex)
{
	t_cmdito	*cmd;

	cmd = init_cmd();
	while (lex->tok && lex->tok->tkn != C_PI && lex->tok->tkn != C_SC)
	{
		if (lex->tok->tkn == WORD)
			cmd->args = append_arg(lex->tok->data, cmd->args, &cmd->n_ar);
		else if (lex->tok->tkn == C_GT || lex->tok->tkn == C_LT
			|| lex->tok->tkn == C_GTGT || lex->tok->tkn == C_LTLT)
			deal_redir(lex, &cmd);
		lex->tok = lex->tok->next;
	}
	if (lex->tok && lex->tok->tkn == C_PI)
		g_sh.hasp = 1;
	add_cmd(&g_sh.cmd, cmd);
	g_sh.nproc++;
}

void	parse(t_lexer lex)
{
	while (lex.tok)
	{
		build_commands(&lex);
		if (lex.tok && lex.tok->data)
			free(lex.tok->data);
		if (lex.tok)
			lex.tok = lex.tok->next;
	}
}

int	lex_parse(char *line)
{
	t_lexer	*lex;

	g_sh.cmd = NULL;
	g_sh.nproc = 0;
	g_sh.hasp = 0;
	if (!lexer(line, &lex) || !check_syntax(lex))
	{
		ft_freelex(&lex->tok, 1);
		free(lex->s);
		free(lex);
		return (0);
	}
	parse(*lex);
	ft_freelex(&lex->tok, 0);
	free(lex->s);
	free(lex);
	return (1);
}
