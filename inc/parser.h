#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

typedef struct s_io
{
	char		*name;
	int			is_out;
	int			is_app;
	struct s_io	*next;
}	t_io;

typedef struct s_cmdito
{
	char			**args;
	int				n_ar;
	t_io			*io;
	pid_t			pid;
	int				freed;
	struct s_cmdito	*next;
}					t_cmdito;

t_cmdito	*init_cmd(void);
int			lex_parse(char *line);
void		new_cmd(t_cmdito **cmd, char *line);
t_io		*new_io(char *name, int is_app, int is_out);
void		add_cmd(t_cmdito **lst, t_cmdito *add);
void		add_redir(t_io **lst, t_io *new);
void		deal_redir(t_lexer *lex, t_cmdito **cmd);
char		**append_arg(char *line, char **ar, int *n);
void		print_cmd(void);
void		ft_freelex(t_token **lst, int flag);
void		ft_freeio(t_io **lst);
void		read_heredoc(t_cmdito **cmd, char *del);

#endif
