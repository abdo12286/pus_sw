#include "push_swap.h"
#include <stdio.h>

void	space(char *av)
{
	int	i;

	i = 0;
	while (av[i] == 32)
		i++;
	if (av[i] == '\0')
		error();
}
int	chick(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (i == ' ')
		{
			i = 1;
			return (i);
		}
		i++;
	}
	return (0);
}

t_list	*one_arg(char *av)
{
	t_list	*new_node;
	int		j;

	j = ft_atoi(av);
	new_node = ft_lstnew(j);
	return (new_node);
}

t_list	*tow_arg(char *av)
{
	char	**arg;
	int		i;
	int		j;
	t_list	*head;
	t_list	*new_node;

	head = NULL;
	i = 0;
	// while(av[i])
	// {
	//     if(!(av[i] <= 32))
	//     {
	//         i=0;
	//         break ;
	//     }
	//     i++;
	// }
	if (!av[i])
		error();
	arg = ft_split(av, ' ');
	while (arg[i])
	{
		j = ft_atoi(arg[i]);
		new_node = ft_lstnew(j);
		if (!head)
			head = new_node;
		else
			ft_lstadd_back(&head, new_node);
		i++;
	}
	return (head);
}

void	new_stack(char **av, t_list **head)
{
	t_list	*new_node;
	int		i;

	i = 1;
	while (av[i])
	{
		if (chick(av[i]) == 0)
			new_node = tow_arg(av[i]);
		else
			new_node = one_arg(av[i]);
		if (!head)
			*head = new_node;
		else
			ft_lstadd_back(head, new_node);
		i++;
	}
}

void	alpha(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isalpha(av[i]))
			error();
		i++;
	}
}
void	plus_and(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) && ((av[i + 1] == '-') || (av[i + 1] == '+')))
			error();
		if (((av[i] == '-') || (av[i] == '+')) && ((av[i + 1] == '-') || (av[i
					+ 1] == '+')))
			error();
		if (((av[i] == '-') || (av[i] == '+')) && !ft_isdigit(av[i + 1]))
			error();
		i++;
	}
}
void	repetition(t_list **stack)
{
	t_list(*tmp), (*node), (*next);
	tmp = *stack;
	node = tmp;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (node->content == next->content)
			{
				free_stack(stack);
				error();
			}
			next = next->next;
		}
		node = tmp->next;
		tmp = tmp->next;
	}
}
int *bubble_sort(t_list *head)
{
    t_list *tmp;
    int *p;
    int i;
    int j;
    int c;

    i = ft_lstsize(head);
    j = 0;
    tmp = head;
    p = malloc(i * sizeof(int));
    if(!p)
    {
        free_stack(&head);
         return(0);
    }  
    while(i > j)
    {
        p[j] = tmp->content;
		//printf("%d ",p[j]);
        j++;
        tmp = tmp->next;
    }
    i = 0;
    while(i < j - 1)
    {
        if(p[i] > p[i + 1])
        {
            c = p[i];
            p[i] = p[i + 1];
            p[i + 1] = c;
            i = 0;
        }
        else
            i++;
    }
    return (p);
}
int	is_sort(t_list **stack_a)
{
	t_list *head;
	t_list *temp;

	head = *stack_a;
	temp = head->next;
	while (temp)
	{
		if(head->content > temp->content)
			return (1);
		temp = temp->next;
		head = head->next;
	}
	exit(0);
}

int    get_range(int size)
{
    if (size <= 16)
        return (size / 2);
    else if (size <= 100)
        return (size / 5);
    else if (size <= 500)
        return (size / 12);
    else
        return (35);
}
void	three(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	t_list *temp1;
	t_list *temp2;
	
	temp = *stack_a;
	temp1 = temp->next;
	temp2 = temp1->next;
	if(temp->content > temp1->content && temp1->content > temp2->content)
	{
		rra(stack_a);
		pa(stack_a,stack_b);
		sa(stack_a);
		pb(stack_a,stack_b);
	}
	else if(temp->content > temp1->content && temp->content < temp2->content)
		sa(stack_a);
	else if(temp->content < temp1->content && temp->content > temp2->content)
		rra(stack_a);
	else if(temp->content < temp1->content && temp1->content > temp2->content)
	{
		pa(stack_a,stack_b);
		sa(stack_a);
		pb(stack_a,stack_b);
	}
	else if(temp->content > temp1->content && temp->content > temp2->content)
		ra(stack_a);
}

void mohim(t_list **stack_a, t_list **stack_b, int *p)
{
	t_list *tem_a;
	t_list *head_b;

	int size;
	int range;
	int start;
	int j;
	t_list	*tem_b;

	size = ft_lstsize(*stack_a);
	range = get_range(size);
	start = 0;
	while (start < size)
    {
		
		j = start ;
		while(j < range)
		{
			
			tem_a = *stack_a;
			if(p[j] == tem_a->content)
			{
				
				pa(stack_a,stack_b);
				head_b = (*stack_b);
				tem_b = head_b->next;
				if(tem_b)
					if(head_b->content < tem_b->content)
						rb(stack_b);
				j = 0;
				break;
			}
			j++;
		}
		if(j != 0)
		{
			if(p[start] > tem_a->content)
			{
				pa(stack_a,stack_b);
				head_b = (*stack_b);
				tem_b = head_b->next;
				if(tem_b)
					if(head_b->content < tem_b->content)
						rb(stack_b);
			}
				
			else
				ra(stack_a);
		}
		if(range < size)
			range = range + 1;
		start++;
		if(start == size && ft_lstsize(*stack_a) != 0)
			start = size - ft_lstsize(*stack_a);
    }
}
int ch(t_list **stack_b)
{
	t_list *head;
	t_list *temp;

	head = (*stack_b);
	temp = head->next;
	while(temp)
	{
		if(head->content < temp->content)
			return(1);
		temp = temp->next;
	}
	return (0);
}
void mohim2(t_list **stack_a, t_list **stack_b)
{
	int size;
	t_list *temp_a;
	t_list *head_a;

	size = ft_lstsize(*stack_b);
	printf("(%d)",size);
	while(size > 0)
	{
		//(*stack_a) = 
		if(ch(stack_b) == 0)
		{
			pb(stack_a,stack_b);
			head_a = (*stack_a);
			temp_a = head_a->next;
			if(temp_a)
				if(head_a->content > temp_a->content)
					ra(stack_a);
		}
		else
			pb(stack_a,stack_b);
		size  = ft_lstsize(*stack_b);
	}

}

int	main(int ac, char **av)
{
	int i;
	int size;
	t_list *stack_a;
	t_list *stack_b;
	 t_list *tmp_a;
	 t_list *tmp_b;
    int *p;
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac > 1)
	{
		while (ac > i)
		{
			if (!av[i][0])
				error();
			space(av[i]);
			alpha(av[i]);
			plus_and(av[i]);
			i++;
		}
		new_stack(av, &stack_a);
		repetition(&stack_a);
        p = bubble_sort(stack_a);
		i = is_sort(&stack_a);
		size = ft_lstsize(stack_a);
		if(size > 3)
		{
			mohim(&stack_a,&stack_b,p);
			mohim2(&stack_a,&stack_b);
		}
		else
			three(&stack_a,&stack_b);
		
		tmp_a = stack_a;
		tmp_b = stack_b;
        while(tmp_a)
        {
			
            printf("%d ",tmp_a->content);
			tmp_a = tmp_a->next;
        }
		printf("\n");
		while(tmp_b)
        {
            printf("%d ",tmp_b->content);
			tmp_b = tmp_b->next;
		
         }

	}

	else
	{
		write(1, "Errrtrror\n", 6);
		return (1);
	}
	free(p);
}
