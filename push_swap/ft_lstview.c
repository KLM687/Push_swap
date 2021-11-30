#include "push_swap.h"



void	ft_lstview(t_list *lst)
{
	while (lst)
	{
		printf(" %d\n",lst->content);
		lst = lst->next;
	}
	printf("-\n");
}