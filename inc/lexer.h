#ifndef LEXER_H
# define LEXER_H

# define WORD 1

enum e_chrtype
{
	C_NRL = -42,
	C_PI = '|',
	C_AM = '&',
	C_SQ = '\'',
	C_DQ = '"',
	C_SC = ';',
	C_SP = ' ',
	C_GT = '>',
	C_LT = '<',
	C_BL = '\\',
	C_DL = '$',
	C_GTGT = -44,
	C_LTLT = -45,
	C_HD_SC = -43,
	C_NULL = 0,
};

enum e_states
{
	S_DQ,
	S_SQ,
	S_NRL
};

typedef struct s_token
{
	char			*data;
	int				tkn;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	char	*s;
	t_token	*tok;
	int		esc;
	int		state;
	int		cb;
}	t_lexer;

int			lexer(char *s, t_lexer **lex);
void		new_token(t_token **tok);
int			get_type(char c);
char		*ft_strchjoin(char *str, char c);
void		deal_char(t_token *tok, char c, int nstat, t_lexer **lex);
void		nrml_state(int *i, t_token **tok, t_lexer **lex);
void		double_quotes(int *i, t_token **tok, t_lexer **lex);
void		simple_quotes(char c, t_token **tok, t_lexer **lex);
int			expand_env(t_lexer **lex, int i, t_token **tok);
char		*get_val(char *s, int i, int ret);
int			get_len(char *s, int i);
char		*scan_line(char *line);
int			check_syntax(const t_lexer *lex);
char		*reconstruct(char *line);

#endif