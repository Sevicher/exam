#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*previous;

	temp = *begin_list;
	previous = *begin_list;
	while (*temp)
	{
		if ((*cmp)(temp->data, data_ref) == 0)
		{
			free(temp->data);
			previous->next = temp->next;
		previous = temp;
		temp = temp->next;
	}
}
