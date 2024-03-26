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

// void fill_stack_b(t_stack **a, t_stack **b)
// {
//     t_stack *curr;
//     t_stack *prev;
    
//     if (*b == NULL)
//     {
//         *b = (t_stack *)malloc(sizeof(t_stack));
//         (*b) ->next = NULL;
//     }
//     prev = NULL;
//     curr = *a;
//     while (curr != NULL)
//     {
//         if (prev == NULL)
//             *a = curr->next;
//         else
//             prev ->next = curr->next;
//         curr->next = *b;
//         *a = curr;
//         curr = *a;
//     }
// }
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
    int i = 0;

    while (argv[i] != NULL)
    {
        new = ft_lstnew(ft_atoi(argv[i]));
        if (!new)
            return ;
        ft_lstadd_back(a, new);
        i++;
    }
}
// void free_stack(t_stack **a)
// {
//     t_stack *tmp;

//     if (*a == NULL)
//         return ;
//     while (*a != NULL)
//     {
//         tmp = *a;
//         *a = (*a) -> next;
//         free(tmp);
//     }
// }
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
    t_stack *a;
    int *arr;

    arr = NULL;
    a = malloc(sizeof(t_stack));
    if (argc < 2)
        exit(0);
   else
        ft_split_args(&a, argv);
        if (argc == 2)
            sort2(&a);
        if ( argc == 4)
            sort3(&a);
        else
            sort_big(&a);
    return (0);
}