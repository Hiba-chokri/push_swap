void swap_a(t_stack **top)
{
     t_stack *tmp;

	tmp = top -> next;
	top-> next = tmp -> next;
	tmp->next=top;
	top=tmp;
    write(1, "sa\n", 3);
}
void swap_b(t_stack **top)
{
    t_stack *tmp;

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
    write(1, "ra\n", 3);
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
    write(1, "rb\n", 3);
}
void rr_a(t_stack **top)
{
    t_stack *tmp;

    tmp = top;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = top;
    top = tmp;
    write(1, "rra\n", 4);
}
void rr_b(t_stack **top)
{
    t_stack *tmp;

    tmp = top;
    while (tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = top;
    top = tmp;
    write(1, "rrb\n", 4);
}

void push_a(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if(*b != NULL)
    {
        tmp = *b;
        *b = (*b) -> next;
        tmp -> next = *a;
        *a = tmp;
    }
    else
        return ;
}

void push_b(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    if (*a != NUll)
    {
        tmp = *a;
        *a = *a -> next;
        tmp -> next = *b;

    }
    else
        return ;
}

void rrr(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    t_stack *ptr;

    tmp = *a;
    ptr = *b;
    while(tmp -> next != NULL)
        tmp = tmp -> next;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    tmp -> next = *a;
    ptr -> next = *b;
    *a = tmp;
    *b = ptr;
    write(1, "rrr\n", 4);
}

void ss(t_stack **a, t_stack **b)
{
    swap_a(a);
    swap_b(b);
    write(1, "ss\n", 3);
}
typedef struct s_stack
{
    int *data;
    struct s_stack *next;
} t_stack;