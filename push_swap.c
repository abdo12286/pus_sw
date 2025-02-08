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
void	three(t_list **stack_a, t_list **stack_b, int *p, int size, int range)
{
	t_list *temp;
	int a;
	int start;

	a = 0;
	start =0;
	temp = *stack_a;
	while(start < size)
	{
		if()

	}
}

void mohim(t_list **stack_a, t_list **stack_b, int *p)
{
	t_list *tem_a;
	int size;
	int range;
	int start;
	//int end;
	int j;

	tem_a = *stack_a;
	size = ft_lstsize(*stack_a);
	range = get_range(size);
	start = 0;
	//end = range + start;
	while (start < size)
    {
        // if(end != size)
        //     end = range + start;
        j = start ;
        //printf("((%d))\n",p[start]);
        while (j < range)
        {
             //printf("%d",p[j]);
            // printf("(%d) \n",tem_a->content);
            if(tem_a->content == p[j])
            {
                pa(stack_a,stack_b);
                // if(tem_b->next)
                // {
                //     c = tem_b->next;
                //     if(tem_b->content > c->content)
                //         rrb(stack_b);
                // }
            }
            j++;
        }
		tem_a = *stack_a;
        start++;
        if(range < size)
            range++;
    }
    // printf("%d ",range);
    // printf("%d ",size);
    // printf("%d \n",j);
}

int	main(int ac, char **av)
{
	int i;
	t_list *stack_a;
	t_list *stack_b;
	t_list *tmp_a;
	t_list *tmp_b;
    int *p;

	int size;
	int range;



	stack_a = NULL;
	stack_b = NULL;
	//printf("%d",stack_b->content);
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
		i = 0;
		new_stack(av, &stack_a);
		repetition(&stack_a);
        p = bubble_sort(stack_a);
		size = ft_lstsize(stack_a);
		range = get_range(size);
		mohim(&stack_a,&stack_b,p);
		// t_list *a = ft_lstnew(100);
		// ft_lstadd_back(&stack_b,a);
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