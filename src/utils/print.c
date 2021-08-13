#include "../../inc/minishell.h"

void	print_cmd(void)
{
	int			i;
	static int	j = 0;
	t_cmdito	*ctmp;
	t_io		*itmp;

	printf("PIPELINE %d\n", ++j);
	ctmp = g_sh.cmd;
	while (ctmp)
	{
		if (ctmp->args[0])
			printf("	CMD: %s\n", ctmp->args[0]);
		i = 0;
		while (ctmp->args[++i])
			printf("	ARGS: %s\n", ctmp->args[i]);
		itmp = ctmp->io;
		while (itmp)
		{
			printf("	FILE: %s\n", itmp->name);
			printf("	IS APPEND: %d\n", itmp->is_app);
			printf("	IS OUTPUT: %d\n", itmp->is_out);
			itmp = itmp->next;
		}
		ctmp = ctmp->next;
	}
}
