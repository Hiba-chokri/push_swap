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
 fill_stack(t_stack *top, int argc, char *argv[])
{
    t_stack *tmp;
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
        ft_lstadd_back(&tmp, new);
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

    max = top -> data;
    while (top -> next != NULL)
    {
        if (top -> data < top -> next -> data)
            max = top -> next -> data;
        top = top -> next;
    }
    // condtions of sorting
    // if the max element is in the beginning of the stack
    // if the max element is in the middle of the stack
    // if the max element is in the end of the stack
    

}

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    int *arr;

    fillstack(&a, argc, argv);
    arr = fill_arr(argc, argv);
    bubbleSort(arr, argc);
    
}
