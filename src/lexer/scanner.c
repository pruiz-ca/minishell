#include "minishell.h"

static void	set_state(char c, int *state)
{
	if (*state == S_NRL && c != ';')
	{
		if (c == C_DQ)
			*state = S_DQ;
		else if (c == C_SQ)
			*state = S_SQ;
	}
	else if (c == C_DQ && *state == S_DQ)
		*state = S_NRL;
	else if (c == C_SQ && *state == S_SQ)
		*state = S_NRL;
}

char	*reconstruct(char *line)
{
	int		state;
	int		i;
	char	*new;

	i = -1;
	state = S_NRL;
	line = ft_strtrim(line, " \t");
	if (line[0] == ';' && printf("%s`%c'\n", SYNTAX_E, ';'))
		return (NULL);
	new = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	while (line[++i])
	{
		new[i] = line[i];
		set_state(new[i], &state);
		if (new[i] == ';' && (state == S_SQ || state == S_DQ
				|| (new[i - 1] == C_BL)))
			new[i] = HID_SC;
	}
	free(line);
	return (new);
}
