/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:58:53 by hichokri          #+#    #+#             */
/*   Updated: 2024/03/26 04:16:31 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// // structure of stack


// int	ft_atoi(const char *nptr)
// {
// 	int	i;
// 	int	sign;
// 	int	res;

// 	i = 0;
// 	sign = 1;
// 	res = 0;
// 	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
// 		i++;
// 	if (nptr[i] == '-')
// 	{
// 		sign *= -1;
// 		i++;
// 	}
// 	else if (nptr[i] == '+')
// 		i++;
// 	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
// 	{
// 		res *= 10;
// 		res += nptr[i] - '0';
// 		i++;
// 	}
// 	return (res * sign);
// }

// t_stack	*ft_lstnew(int content)
// {
// 	t_stack	*new_node;

// 	new_node = NULL;
// 	new_node = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->data = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }
// t_stack	*ft_lstlast(t_stack *lst)
// {
// 	t_stack	*ptr;

// 	if (!lst)
// 		return (NULL);
// 	ptr = lst;
// 	while (ptr->next != NULL)
// 		ptr = ptr->next;
// 	return (ptr);
// }

// void	ft_lstadd_back(t_stack **lst, t_stack *new)
// {
// 	if (lst == NULL)
// 		return ;
// 	if (*lst == NULL)
// 		*lst = new;
//     else
// 		ft_lstlast(*lst)->next = new;
// }

// void	ft_lstadd_front(t_stack **lst, t_stack *new)
// {
// 	if (lst == NULL || new == NULL)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }
// // fill stack a;
//  fill_stack_a(t_stack *top, int argc, char *argv[])
// {
//     t_stack *new;
//     int i;

//     i = 1;
//     while (i < argc)
//     {
//         new = ft_lstnew(ft_atoi(argv[i]));
//         if (!new)
//         {
//             write(2, "Error\n", 6);
//             exit(1);
//         }
//         ft_lstadd_back(&top, new);
//         i++;
//     }
//     while(top)
//     {
//         printf("%d\n", top->data);
//         top = top->next;
//     }
// }
// int *fill_arr(int argc, char *argv[])
// {
//     int *tab;
//     int i;
//     int j;


//     j = 0;
//     i = 1;
//     tab = (int *)malloc(argc - 1 * sizeof(int));
//     if (!tab)
//         return (NULL);
//     while (i < argc)
//     {
//         tab[j] = ft_atoi(argv[i]);
//         i++;
//         j++;
//     }
//     return (tab);
// }
// int main(int argc ,char *argv[])
// {
//     t_stack *a;
//     int i;
//     int *arr;
//     fill_stack_a(a, argc, argv);
//     arr = fill_arr(argc, argv);
//     i = 0;
//     while(i < argc )
//     {
//         printf("%d\n", arr[i]);
//         i++;
//     }
// }

// typedef struct s_stack
// {
//     int data;
//     struct s_stack *next;
// }              t_stack;

void swap_a(t_stack **top)
{
     t_stack *tmp;
    // dprintf(2,"tets\n");
    if (!top || !*top)
        return ;
    if ((*top)->data < (*top)->next->data)
    {
        tmp = *top;
        *top = (*top)->next;
        tmp->next = NULL;
        (*top)->next = tmp; 
    }
    write(1, "sa\n", 3);
}
void swap_b(t_stack **top)
{
    t_stack *tmp;
    // printf("tets\n");
    if (!top || !*top || !((*top)->next))
        return ;
	tmp = (*top)->next;
	(*top)->next = tmp->next;
	tmp->next=*top;
	*top=tmp;
    write(1, "sb\n", 3);
}
// rotate
void rotate_a(t_stack **top)
{
    t_stack *tmp;
    // t_stack *ptr;

    if (!top || !*top || !((*top)->next))
        return ;
    // ptr = *top;
    tmp = *top;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *top;
    *top = (*top)->next;
    tmp->next->next = NULL;
    write(1, "ra\n", 3);
}
void rotate_b(t_stack **top)
{
    t_stack *tmp;

    if (!top || !*top || !((*top)->next))
        return ;
    tmp = *top;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *top;
    *top = (*top)->next;
    write(1, "rb\n", 3);
}
void ft_rr(t_stack **top)
{
    t_stack *tmp;
    t_stack *before_lst;

    if (!top || !*top || !((*top)->next))
        return ;
    tmp = *top;
    before_lst = *top;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *top;
    *top = tmp;
    while (before_lst->next != tmp)
        before_lst = before_lst->next;
    before_lst->next = NULL;
}

void rra(t_stack **top)
{
    ft_rr(top);
    write(1, "rra\n",4);
}
void rrb(t_stack **top)
{
    ft_rr(top);
    write(1, "rrb\n",4);
}

void push_a(t_stack **a, t_stack **b)
{
    t_stack *tmp;


    if(*b != NULL)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = *a;
        *a = tmp;
        write(1, "pa\n", 3);
    }
}

void push_b(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    if (*a != NULL)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = *b;
        write(1, "pb\n", 3);
    }
}

void rrr(t_stack **a, t_stack **b)
{

    ft_rr(a);
    ft_rr(b);
    write(1, "rrr\n", 4);
}

void ft_ss(t_stack **a, t_stack **b)
{
    swap_a(a);
    swap_b(b);
    write(1, "ss\n", 3);
}
// int	ft_atoi(const char *nptr)
// {
// 	int	i;
// 	int	sign;
// 	int	res;

// 	i = 0;
// 	sign = 1;
// 	res = 0;
// 	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
// 		i++;
// 	if (nptr[i] == '-')
// 	{
// 		sign *= -1;
// 		i++;
// 	}
// 	else if (nptr[i] == '+')
// 		i++;
// 	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
// 	{
// 		res *= 10;
// 		res += nptr[i] - '0';
// 		i++;
// 	}
// 	return (res * sign);
// }

// t_stack	*ft_lstnew(int content)
// {
// 	t_stack	*new_node;

// 	new_node = NULL;
// 	new_node = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->data = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }
// t_stack	*ft_lstlast (t_stack *lst)
// {
// 	t_stack	*ptr;

// 	if (!lst)
// 		return (NULL);
// 	ptr = lst;
// 	while (ptr->next != NULL)
// 		ptr = ptr->next;
// 	return (ptr);
// }

// void	ft_lstadd_back(t_stack **lst, t_stack *new)
// {
// 	if (lst == NULL)
// 		return ;
// 	if (*lst == NULL)
// 		*lst = new;
//     else
// 		ft_lstlast(*lst)->next = new;
// }

// void	ft_lstadd_front(t_stack **lst, t_stack *new)
// {
// 	if (lst == NULL || new == NULL)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }


//create a pointer to the top of the stack
// fill the stack with the args values
void fill_stack_a(t_stack *top, int argc, char *argv[])
{
    t_stack *new;
    int i;

    i = 1;
    while (i < argc)
    {
        new = ft_lstnew(atoi(argv[i]));
        if (!new)
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        ft_lstadd_back(&top, new);
        i++;
    }
}
int *fill_arr(int argc, char *argv[])
{
    int *tab;
    int i;
    int j;


    j = 0;
    i = 1;
    tab = (int *)malloc(argc - 1 * sizeof(int));
    if (!tab)
        return (NULL);
    while (i < argc)
    {
        tab[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    return (tab);
}

// sort 3  elements
void sort3(t_stack **top)
{
    int i=0;
    i = ft_lstsize(*top); 
            printf("test%d\n", i);
    if (i == 3 && ((*top)->data > (*top)->next->data) && ((*top)->data < (*top)->next->next->data))
    {
        printf("te\n");
        if ((*top)->next->data < (*top)->next->next->data)
        {
            swap_a(top);
        }
        else
        {
            swap_a(top);
            ft_rr(top);
        }
    }
    
}

    // conditions of sorting
    // if the max element is in the beginning of the stack
    // if the max element is in the middle of the stack
    // if the max element is in the end of the stack

void fill_stack_b(t_stack **a, t_stack **b)
{
    t_stack *curr;
    t_stack *prev;
    
    // create the stack b
    if (*b == NULL)
    {
        *b = (t_stack *)malloc(sizeof(t_stack));
        (*b) ->next = NULL;
    }
    prev = NULL;
    curr = *a;
    while (curr != NULL)
    {
        if (prev == NULL)
            *a = curr->next;
        else
            prev ->next = curr->next;
        curr->next = *b;
        *a = curr;
        curr = *a;
    }
}
// calculate the size of the stack
int calculate_size(t_stack *a)
{
    int size;
    t_stack *tmp;

    size = 0;
    tmp = a;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp -> next;
    }
    return (size);
}

int find_min(t_stack *a)
{
    t_stack *tmp;
    int min;

    tmp = a;
    min = tmp -> data;
    while (tmp != NULL)
    {
        if (tmp -> data < min)
            min = tmp -> data;
        tmp = tmp -> next;
    }
    return (min);
}
// find the biggest element in the stack
int find_max(t_stack *a)
{
    t_stack *tmp;
    int max;

    tmp = a;
    max = tmp -> data;
    while (tmp != NULL)
    {
        if (tmp -> data > max)
            max = tmp -> data;
        tmp = tmp -> next;
    }
    return (max);
}
// find the index of the element in the stack
int find_index(t_stack *x, int nb)
{
    int index;

    index = 0;
    while (x != NULL && x-> data != nb)
    {
        index++;
        x = x->next;
    }
    return (index);
}
// calculate the cost of the element in the stack

int calculate_cost(t_stack **a, int size)
{
    int cost;
    int mid;
    int index;
    t_stack *tmp;

    mid = size / 2;
    cost = 0;
    tmp = *a;
    index = 0;
    if (tmp != NULL)
    {
        if (tmp->data < mid)
            cost = index;
        else
            cost = size - index;
        tmp = tmp -> next;
        index++;
    }
    return (cost);
}
// find the element with the minimum cost
int find_min_cost(t_stack *a, int size)
{
    int min;
    int cost;
    int min_cost;
    t_stack *tmp;

    tmp = a;
    min = find_min(a);
    min_cost = calculate_cost(&a, size);
    while (tmp != NULL)
    {
        cost = calculate_cost(&a, size);
        if (cost < min_cost)
        {
            min = tmp -> data;
            min_cost = cost;
        }
        tmp = tmp -> next;
    }
    return (min);
}

// find the index of the element with the minimum cost
int find_min_cost_index(t_stack *a, int size)
{
    int min;
    int cost;
    int min_cost;
    int index;
    t_stack *tmp;

    tmp = a;
    min = find_min(a);
    min_cost = calculate_cost(&a, size);
    index = 0;
    while (tmp != NULL)
    {
        cost = calculate_cost(&a, size);
        if (cost < min_cost)
        {
            min = tmp -> data;
            min_cost = cost;
            index = find_index(a, min);
        }
        tmp = tmp -> next;
    }
    return (index);
}
// checks if the stack include doubles
int check_double(t_stack *a)
{

    while (a != NULL)
    {
        if (a->data == a->next->data)
            return (1);
        a = a->next;
    }
    return (0);
}
void ft_split_args(t_stack **a, char *argv[])
{
    t_stack *new;
    char **tab;
    int arg = 0;
    int i;
    int j;

    i = 0;
    // printf("%s\n", tab[0]);
    while (tab[i] != NULL)
    {
        arg = ft_atoi(tab[i]);
        // printf("%d\n",arg);
        new = ft_lstnew(arg);
        if (!new)
          exit(1);
        ft_lstadd_back(a, new);
        i++;
    }
}

void free_stack(t_stack **a)
{
    t_stack *tmp;

    if (*a == NULL)
        return ;
    while (*a != NULL)
    {
        tmp = *a;
        *a = (*a) -> next;
        free(tmp);
    }
}
int is_stack_sorted(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    while (tmp -> next != NULL)
    {
        if (tmp -> data > tmp -> next -> data)
            return (0);
        tmp = tmp -> next;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    t_stack *a = NULL;
    // t_stack *tmp = NULL;
    int *arr;
    // int i = 0;

    arr = NULL;
    // a = malloc(sizeof(t_stack));
    // tmp =  malloc(sizeof(t_stack));
    if (argc < 2)
        exit(0);
    // if (argc == 2)
    // {
    ft_split_args(&a,argv);
        // fill_stack_a(tmp, argc, argv);
        // free_stack(&tmp);
    // }
    // else
    //     fill_stack_a(a, argc, argv);
    // test array
    // i = 0;
    // while (i < argc - 1)
    // {
    //     printf("%d\n", arr[i]);
    //     i++;
    // }
    // if (argc == 4)
    sort3(&a);
    // printf("test\n");
    return (0);
}