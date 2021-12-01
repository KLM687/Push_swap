#include "push_swap.h"



void	ft_lstview(t_list *lst)
{
	while (lst)
	{
		printf(" %d : %d\n",lst->content, lst->state);
		lst = lst->next;
	}
	printf("-\n");
}