/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:58:53 by hichokri          #+#    #+#             */
/*   Updated: 2024/03/27 03:34:21 by hichokri         ###   ########.fr       */
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

void ft_split_args(t_stack **a,int argc, char *argv[])
{
    t_stack *new;
    int i = 1;
    int j;
    int ar = 0;
    char    **tab;
    
    new = NULL;
    while (i < argc)
    {
        j = 0;
        tab = ft_split(argv[i], ' ');
        while (tab[j])
        {
            ar = ft_atoi(tab[j]);
            while (ar == 0 && tab[j][0] != '0')
            {
                if(tab[j][0] == '-' || tab[j][0] == '+')
                    break;
                exit(1);
            }
            new = ft_lstnew(ar);
            ft_lstadd_back(a, new);
            j++;
        }
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

int check_arg(char **argv)
{
    if(!count_spaces(argv))
        return(0);
    // if(check_character)
    //     return(0);
    // if(check_non_digits)
    //     return(0);
    return(1);
}

int main(int argc, char *argv[])
{
    t_stack *a = NULL;
    int *arr;

    arr = NULL;
    // a = malloc(sizeof(t_stack));
    if (argc < 2)
        exit(0);
    if(!check_arg(argv))
    {
        ft_error();
    }
    
   else
        ft_split_args(&a,argc, argv);
        
        if (ft_lstsize(a) == 2)
            sort2(&a);
        else if ( ft_lstsize(a) == 3)
            sort3(&a);
        // else
        //     sort_big(&a);
    
    while(a != NULL)
    {
        printf("stack_a = %d\n",a->data);
        a = a->next;
    }
    return (0);
}