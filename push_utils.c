#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	nb;

	i = 0;
	j = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		j *= -1;
		i++;
	}
	if(!(str[i] >= '0' && str[i] <= '9'))
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		if (nb > 2147483647|| nb < -2147483648)
			return (2147483648);
		i++;
	}
	return (nb * j);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*itr;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		itr = *lst;
		while (itr->next)
			itr = itr->next;
		itr->next = new;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void free_stack(t_list **stack)
{
    t_list *lst;
    t_list *s;

    lst = *stack;
    while(lst)
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

void error(void)
{
    write(1,"Error\n",6);
    exit(1);
}