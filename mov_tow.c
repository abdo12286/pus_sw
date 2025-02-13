#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;

	head = *stack_a;
	tmp = head->next;
	head->next = NULL;
	*stack_a = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	write(1,"ra\n",3);
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head;

	
	tmp = (*stack_b)->next;
	
		head = *stack_b;
		*stack_b = tmp;
		head->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = head;
		
	write(1,"rb\n",3);
}
void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		rb(stack_b);
	else if (!stack_b)
		ra(stack_a);
	else
	{
		rb(stack_b);
		ra(stack_a);
	}
	write(1,"rr\n",3);
}
void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*lst;

	head = *stack_a;
	tmp = head;
	lst = head;
	while (tmp->next)
		tmp = tmp->next;
	while (lst->next->next)
		lst = lst->next;
	lst->next = NULL;
	tmp->next = head;
	*stack_a = tmp;
	write(1,"rra\n",4);
}
void	rrb(t_list **stack_b)
{
	t_list *tmp;
	t_list *head;
	t_list *lst;
	head = *stack_b;
	tmp = head;
	lst = head;
	while (tmp->next)
		tmp = tmp->next;
	while (lst->next->next)
		lst = lst->next;
	lst->next = NULL;
	tmp->next = head;
	*stack_b = tmp;
	write(1,"rrb\n",4);
}