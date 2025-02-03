#include "push_swap.h"
#include <stdio.h>

void space(char *av)
{
    int i;

    i = 0;
    while(av[i] == 32)
        i++;
    if(av[i] == '\0')
        error(); 
}
int chick(char *av)
{
    int     i;

    i = 0;
    while(av[i])
    {
        if(i == ' ')
        {
            i = 1;
            return (i);
        }
            
        i++;
    }
    return (0);
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

t_list  *one_arg(char *av)
{
    t_list *new_node;
    int j;
 
    j = ft_atoi(av);
    new_node = ft_lstnew(j);
    return (new_node);
}

t_list   *tow_arg(char *av)
{
    char **arg;
    int i;
    int j;
    t_list *head = NULL;
    t_list *new_node;
    i = 0;
    while(av[i])
    {
        if(!(av[i] <= 32))
        {
            i=0;
            break;
        }   
        i++;
    }
    if(!av[i])
        error();
    arg = ft_split(av,' ');
    while(arg[i])
    {
        j = ft_atoi(arg[i]);
        new_node = ft_lstnew(j);
        if(!head)
            head = new_node;
        else
        {
            ft_lstadd_back(&head, new_node);    
        }       
        i++;
    }
    // printf("%d->",head->next);
    return (head);
}
void new_stack (char **av, t_list **head)
{
  
    t_list *new_node;
    int i;

    i = 1;
    while(av[i])
    {
        if(chick(av[i]) == 0)
            new_node = tow_arg(av[i]);
        else
            new_node = one_arg(av[i]);
        if(!head)
            *head = new_node;
        else
            ft_lstadd_back(head,new_node);
        i++;
    }
}

void alpha(char *av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if(ft_isalpha(av[i]))
            error();
        i++;
    }
}
void plus_and(char *av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if (ft_isdigit(av[i]) && ((av[i + 1] == '-') || (av[i + 1] == '+')))
            error();
        if (((av[i] == '-') || (av[i] == '+')) && ((av[i + 1] == '-') || (av[i + 1] == '+')))
            error();
        if (((av[i] == '-') || (av[i] == '+')) && !ft_isdigit(av[i + 1]))
            error();
        i++;
    }
}

int main(int ac, char **av)
{
    int i;
    //int j;
    t_list  *head; 

    i = 1;
    if(ac > 1)
    {
        while (ac > i)
        {
            if(!av[i][0])
                error();
            space(av[i]);
            alpha(av[i]);
            plus_and(av[i]);
            i++;
        }
    }
        
    else
    {
        write(1,"Errrtrror\n",6);
        return(1);
    }
        
    
}