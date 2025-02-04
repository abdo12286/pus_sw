#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	free_stack(t_list **stack)
{
	t_list	*lst;
	t_list	*s;

	lst = *stack;
	while (lst)
	{
		s = lst->next;
		free(lst);
		lst = s;
	}
}
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}