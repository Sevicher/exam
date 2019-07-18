#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int count;
	t_list *start;

	count = 0;
	start = begin_list;
	if (!begin_list)
		return (0);
	while (start)
	{
		++count;
		start = start->next;
	}
	return (count);
}
