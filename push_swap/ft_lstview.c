#include "push_swap.h"



void	ft_lstview(t_list *lst)
{
	while (lst)
	{
		printf("nb = %d\n",lst->content);
		printf("grade = %d\n",lst->grade);
		lst = lst->next;
	}
	printf("-\n");
}