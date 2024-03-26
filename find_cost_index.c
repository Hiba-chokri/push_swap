#include "push_swap.h"

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