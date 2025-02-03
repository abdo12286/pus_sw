#include "push_swap.h"

void sa(t_list ** stack_a)
{
    t_list *tmp;
    t_list *head;

    head = *stack_a;
    tmp  = head->next;
    head->next = tmp->next;
    tmp->next = head;
    *stack_a = tmp;
}

void sb(t_list **stack_b)
{
    t_list *tmp;
    t_list *head;

    head = *stack_b;
    tmp  = head->next;
    head->next = tmp->next;
    tmp->next = head;
    *stack_b = tmp;
}
void ss(t_list **stack_a, t_list **stack_b)
{
    if(!stack_a)
        sb(stack_b);
    else if(!stack_b)
        sa(stack_a);
    else
       {
            sb(stack_b);
            sa(stack_a);
       } 
}
void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *head_b;
    t_list *tmp_a;
    if(stack_b)
    {
        head_a = *stack_a;
        head_b = *stack_b;
        tmp_a = head_a->next;
        head_a->next = head_b;
        *stack_a = tmp_a;
        *stack_b = head_a;

    }
}
void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *head_b;
    t_list *tmp_b;
    if(stack_b)
    {
        head_a = *stack_a;
        head_b = *stack_b;
        tmp_b = head_b->next;
        head_b->next = head_a;
        *stack_b = tmp_b;
        *stack_a = head_b;

    }
}