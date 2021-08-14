
SHELL		=	/bin/bash

NAME		=	minishell

S			=	src/
I			=	inc/
B			=	builtins/
U			=	utils/
O			=	obj/
P			=	parser/
L			=	lexer/
E			=	exec/

NOCOL		=	\033[0m
RED			=	\033[1;31m
ORG			=	\033[0;33m
YEL			=	\033[1;33m
GRN			=	\033[1;32m
BLU			=	\033[0;34m
CYN			=	\033[0;36m

SRCS		=	$Smain.c \
				$S$Uprompt.c $S$Ufrees.c $S$Uerrors.c $S$Uprint.c $S$Uget_line.c $S$Usignals.c $S$Ulist2array.c \
				$S$Llexer.c $S$Ll_utils.c $S$Lstates.c $S$Lexpand.c $S$Lscanner.c \
				$S$Pparser.c $S$Pp_utils.c $S$Plist_utils.c $S$Pheredoc.c\
				$S$Bft_cd.c $S$Bft_echo.c $S$Bft_env.c $S$Bft_exit.c $S$Bft_export.c \
				$S$Bft_pwd.c $S$Bft_unset.c \
				$S$Bb_utils.c $S$Benv_utils.c $S$Benv_utils2.c $S$Benv_utils3.c \
				$S$Eft_execute.c $S$Ee_utils.c $S$Eft_redirs.c

OBJS		=	$(SRCS:$S%.c=$O%.o)

HEADER		=	-I $I

LIBS		=	-lreadline -L lib/ -lft

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

EXTRA		=	#-fsanitize=address

start:
				@[ -f "minishell" ] || echo -e -n "$(ORG)[Dependecies]:\t$(NOCOL)"
				@make -s all

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo -e "$(GRN) ==> Success!$(NOCOL)"
				@echo -e -n "$(ORG)[Libft]:\t$(NOCOL)"
				@make -s -C lib/
				@echo -e -n "$(ORG)[Linking]:\t$(NOCOL)"
				@$(CC) $(FLAGS) $(EXTRA) $(SRCS) $(HEADER) $(LIBS) -o $(NAME)
				@echo -e "$(GRN)==> Success!$(NOCOL)"

$O%.o: 			$S%.c
				@[ -d $(O) ] || mkdir -p $(O)
				@[ -d $(O)$(B) ] || mkdir -p $(O)$(B)
				@[ -d $(O)$(U) ] || mkdir -p $(O)$(U)
				@[ -d $(O)$(L) ] || mkdir -p $(O)$(L)
				@[ -d $(O)$(P) ] || mkdir -p $(O)$(P)
				@[ -d $(O)$(E) ] || mkdir -p $(O)$(E)
				@echo -e -n "$(ORG)*$(NOCOL)"
				@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@

clean:
				@rm -rf $(O)
				@rm -rf .tmp*
				@echo -e "$(RED)Cleaning obj files..$(NOCOL)"
				@make clean -C lib/ > /dev/null

fclean:			clean
				@echo -e "$(RED)Cleaning $(NAME)..$(NOCOL)"
				@rm -f $(NAME)
				@rm -f lib/libft.a
				@rm -rf minishell.dSYM
				@find . -name ".DS_Store" -delete

re:				fclean all

run:			re
				@make clean
				./minishell

norm:
				@norminette $(ls -Rl | grep *.c *.h)

.PHONY:			all clean fclean re run norm
