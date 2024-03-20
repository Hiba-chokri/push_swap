#include "push_swap.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// steps
//create a structrure that will represent the stack
typedef struct s_stack
{
    int *data;
    struct s_stack *next;
} t_stack;
//create a pointer to the top of the stack
t_stack *top;
// fill the stack with the args values
 fill_stack_a(t_stack *top, int argc, char *argv[])
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
    int max;

    if (top > top -> next)
    {
        max = top;
        rotate(&top);
    }
    else if (top -> next > top)
    {
        max = top -> next;
        rotate_a(&(top -> next));
        swap_a(&(top -> next));
    }
    if (top > top -> next)
        swap_a(&top);
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
        (*b) -> next = NULL;
    }
    prev = NULL;
    curr = *a;
    while (curr != NULL)
    {
        if (prev == NULL)
            *a = curr -> next;
        else
            prev -> next = curr -> next;
        curr -> next = *b;
        *a = curr;
        curr = *a;
    }
}

void sort5(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    t_stack *top;
    fill_stack_b(&a, &b);// move the top 2 elements of stack a into stack b
    sort3(&a); // sort the rest 3 elements of stack a
                // sort the 2 elements of stack b
    tmp = *b;
    if (tmp > tmp -> next)
        t
}
{
    // move the top 2 elements of stack a into stack b

}
// function to calcluate the size
int calculate_size(t_stack *a)
{
    int ptr;
    int size;

    size = 0;
    ptr = a;
    while (ptr != NULL)
    {
        index++;
        ptr = ptr -> next;
    }
    return (size);

}
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
// int calculate_cost(t_stack **a, int size)
// {
//     int cost;
//     int mid;
//     int index;
//     t_stack *tmp;

//     mid = size / 2;
//     cost = 0;
//     tmp = *a;
//     index = 0;
//     if (tmp != NULL)
//     {
//         if (tmp < mid)
//             cost = index;
//         else
//             cost = size - index;
//         tmp = tmp -> next;
//         index++;
//         return (cost);
//     }
// }
void push_b(t_stack **a, t_stack **b)
{
    
}

int bigger_target(int nb)
{
    int max_target;

    max_target = 0;
    if (nb > max_target)
        max_target = nb;
    return (max_target);
}

int find_max(t_stack *b)
{
    int max;

    max = 0;
    while (b != NULL)
    {
        if (b ->data > max)
            max = b->data;
        b = b->next;
    }
    return (max);
}

int find_target(t_stack *b, int nb)
{
    int target;
    int found;
    int max_targ;

    target = 0;
    found = 0;
    while (b != NULL)
    {
        if (b->data < nb)
        {
            found = 1;
            target = b -> data;
            max_targ = bigger_target(target);
        }
        b = b -> next;
    }
    if (found == 0)
        max_targ = find_max(b);
    return (max_targ);
}

void move_target(t_stack *b, int target, int size)
{
    int mid;

    mid = size / 2;
    if (target < mid)
    {

    }
}
int moves_count(t_stack *x, int nb, int size)
{
    int cost;
    int mid;
    int index;

    cost = 0;
    mid = size / 2;
    index = (x, nb);
    if (index  < mid)
        cost = index;
    else
        cost = size - index;
}
int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    int *arr;
    int size;

    fill_stack_a(&a, argc, argv);
    arr = fill_arr(argc, argv);
    bubbleSort(arr, argc);
    size = calculate_size(a);
    
}
