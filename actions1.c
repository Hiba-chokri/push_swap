#include "push_swap.h"

void swap_a(t_stack **top)
{
     t_stack *tmp;

    if (!top || !*top)
        return ;
    tmp = (*top)->next;
    (*top)->next = (*top)->next->next;
    tmp->next= *top;
    *top = tmp;
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