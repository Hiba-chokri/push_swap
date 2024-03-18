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
void sort5(t_stack **top)
{

}
{
    // move the top 2 elements of stack a into stack b

}

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    int *arr;

    fill_stack_a(&a, argc, argv);
    arr = fill_arr(argc, argv);
    bubbleSort(arr, argc);
    
}
