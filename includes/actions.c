#include "push_swap.h"

void swap_a(t_stack **top)
{
     int tmp;

	tmp = top -> next;
	top-> next = tmp -> next;
	tmp->next=top;
	top=tmp;
    write(1, "sa\n", 3);
}
void swap_b(t_stack **top)
{
    int tmp;

	tmp = top -> next;
	top-> next = tmp -> next;
	tmp->next=top;
	top=tmp;
    write(1, "sb\n", 3);
}
// rotate
void rotate_a(t_stack **top)
{
    t_stack *tmp;
    t_stack *ptr;

    ptr = top;
    tmp = top;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = ptr;
    top = ptr -> next;
}
void rotate_b(t_stack **top)
{
    t_stack *tmp;
    t_stack *ptr;

    ptr = top;
    tmp = top;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = ptr;
    top = ptr -> next;
}
void rrotate_a(t_stack **top)
{
    t_stack *tmp;

    tmp = top;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = top;
    top = tmp;
}
void rrotate_b(t_stack **top)
{
    t_stack *tmp;

    tmp = top;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = top;
    top = tmp;
}