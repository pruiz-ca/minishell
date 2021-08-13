#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <term.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <stdbool.h>
# include <sys/ioctl.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft.h"
# include "parser.h"

# define NOCOL "\001\e[0m\002"
# define RED "\001\e[0;31m\002"
# define GRN "\001\e[0;32m\002"
# define YEL "\001\e[0;33m\002"
# define BLU "\001\e[0;34m\002"
# define MAG "\001\e[0;35m\002"
# define CYN "\001\e[0;36m\002"
# define WHT "\001\e[0;37m\002"

# define SYNTAX_E "minishell: syntax error near unexpected token "
# define QUOTE_E "minishell: missing enclosing quotation mark"
# define CURLY_E "minishell: missing enclosing curly brace"
# define HID_SC -44

# define READ 0
# define WRITE 1

typedef struct s_env
{
	char			*name;
	char			*value;
	int				def;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	t_env			*env;
	t_cmdito		*cmd;
	int				nproc;
	int				hasp;
	int				fd_bak[2];
}					t_shell;

extern t_shell	g_sh;

/*
** Minishell
*/
void	intro(void);
char	*prompt(void);
char	*get_line(void);
void	init_fds(void);

/*
** Frees
*/
void	ft_freecmd(t_cmdito *cmd);
void	ft_freemain(char **tabs, char *line);
void	ft_freeclone(t_env *clone);

/*
** List Utils
*/
void	ft_initenv_list(char **envp, t_env **env);
int		ft_edit_env(t_env **env, char *name, char *newvalue, int haseq);
void	ft_lstadd_back_env(t_env **env, t_env *new);
char	*ft_getenv(char *name);
void	ft_delenv(t_env **env, char *name);
void	ft_sortlist_env(char **args, t_env **env);

/*
** Utils
*/
int		ft_word_count(char **args);
int		ft_isdigit_str(char *str);
int		ft_fileexists(char *file);
void	ft_error(int errornum, char *errormsg, int bye);
void	handle_signals(int flag);
void	sig_main(int signal);
void	sig_fork(int signal);
char	**ft_list2array(t_env *env);

/*
** Built-ins
*/
void	ft_cd(char **args);
void	ft_pwd(void);
void	ft_echo(char **args);
void	ft_trim_args(char ***args);
void	ft_env(char **args, t_env *env);
void	ft_binaries(char **args);
void	ft_export(char **args);
void	ft_printexport(t_env *env);
void	ft_unset(char **args);
void	ft_exit(char **args);
int		ft_isbuiltin(char **args);
void	ft_hub(char **args, int forked);

/*
** Exec
*/
void	ft_execute(t_cmdito *cmd);
void	ft_cmds(t_cmdito *tmp, int old_fd[2], int *i, int islast);
void	ft_exchild(t_cmdito *tmp, int fd[2], int old_fd[2]);
void	ft_exparent(int fd[2], int old_fd[2], int i, int islast);
char	*ft_findbinaries(char **args);
int		ft_redir(t_io *io, int inb);

#endif
