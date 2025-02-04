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
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head;

	head = *stack_b;
	tmp = head->next;
	head->next = NULL;
	*stack_b = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
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
}