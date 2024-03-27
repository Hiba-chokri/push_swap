#include "push_swap.h"

void sort3(t_stack **top)
{
    if (ft_lstsize(*top) > 2 && ((*top)->data > (*top)->next->data) && ((*top)->data < (*top)->next->next->data))
    {
        if ((*top)->next->data < (*top)->next->next->data)
            swap_a(top);
    }
    else if (((*top)->data > (*top)->next->data) && ((*top)->data > (*top)->next->next->data))
    {
        if ((*top)->next->data > (*top)->next->next->data)
            {
                swap_a(top);
                rra(top);
            }
        else
            rotate_a(top);
    }
    else if(((*top)->data < (*top)->next->data) &&  ((*top)->data < (*top)->next->next->data))
    {
        if ((*top)->next->data > (*top)->next->next->data)
            {
                swap_a(top);
                rotate_a(top);
            }
    }
    else if (((*top)->data < (*top)->next->data) && 
        ((*top)->data > (*top)->next->next->data))
        rra(top);
}

void sort2(t_stack **top)
{
    if((*top)->data > (*top)->next->data)
        swap_a(top);
}