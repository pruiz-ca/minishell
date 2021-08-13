#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_item;

	new_item = malloc(sizeof(t_list));
	if (!new_item)
		return (NULL);
	new_item->content = content;
	new_item->next = NULL;
	return (new_item);
}
