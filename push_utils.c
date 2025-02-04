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
	if (!(str[i] >= '0' && str[i] <= '9'))
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		if (nb > 2147483647 || nb < -2147483648)
			error();
		i++;
	}
	return (nb * j);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*itr;
	int		i;

	if (!lst)
		return (0);
	itr = lst;
	i = 0;
	while (itr)
	{
		i++;
		itr = itr->next;
	}
	return (i);
}