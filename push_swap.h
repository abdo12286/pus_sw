
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}                       t_list;

void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
void error(void);
int					ft_isdigit(int c);
int	ft_isalpha(int c);
#endif