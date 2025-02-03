#include "push_swap.h"

void rrr(t_list **stack_a, t_list **stack_b)
{
     if(!stack_a)
        rrb(stack_b);
    else if(!stack_b)
        rra(stack_a);
    else
       {
            rrb(stack_b);
            rra(stack_a);
       }
}