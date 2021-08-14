#include "minishell.h"

void	intro(void)
{
	printf(\
	GRN "              d8b          d8b          888               888 888 \n"\
	GRN "              Y8P          Y8P          888               888 888 \n"\
	YEL "                                        888               888 888 \n"\
	YEL "88888b.d88b.  888 88888b.  888 .d8888b  88888b.   .d88b.  888 888 \n"\
	RED "888 \"888 \"88b 888 888 \"88b 888 88K      888 \"88b d8P  Y8b 888 888 \n"\
	RED "888  888  888 888 888  888 888 \"Y8888b. 888  888 88888888 888 888 \n"\
	MAG "888  888  888 888 888  888 888      X88 888  888 Y8b.     888 888 \n"\
	BLU "888  888  888 888 888  888 888  88888P' 888  888  \"Y8888  888 888 \n"\
	NOCOL "\n");
}

char	*prompt(void)
{
	char	*user;
	char	pdir[1024];
	char	*dir;
	char	*tmp[3];

	user = getenv("USER");
	if (!user)
		user = "user";
	if (!getcwd(pdir, sizeof(pdir)))
		dir = "dir";
	else
		dir = ft_strrchr(pdir, '/');
	if (!(errno == 0))
		tmp[0] = ft_strjoin("\U0001F4A3" CYN, user);
	else
		tmp[0] = ft_strjoin("\U0001F480" CYN, user);
	tmp[1] = ft_strjoin(NOCOL " in " CYN "\U0001F4C2", ++dir);
	tmp[2] = ft_strjoin(tmp[0], tmp[1]);
	free(tmp[0]);
	free(tmp[1]);
	tmp[0] = ft_strjoin(tmp[2], GRN " \u276f " NOCOL);
	free(tmp[2]);
	return (tmp[0]);
}
