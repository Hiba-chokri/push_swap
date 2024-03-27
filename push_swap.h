/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:50:33 by hichokri          #+#    #+#             */
/*   Updated: 2024/03/27 02:59:58 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./includes/libft/libft.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void sort2(t_stack **top);
void sort3(t_stack **top);
void swap_a(t_stack **top);
void swap_b(t_stack **top);
void rotate_a(t_stack **top);
void rotate_b(t_stack **top);
void ft_rr(t_stack **top);
void rra(t_stack **top);
void push_a(t_stack **a, t_stack **b);
void push_b(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b);
void ft_ss(t_stack **a, t_stack **b);
int find_min(t_stack *a);
int find_max(t_stack *a);
int find_index(t_stack *x, int nb);
int calculate_cost(t_stack **a, int size);
int find_min_cost(t_stack *a, int size);
int find_min_cost_index(t_stack *a, int size);
int args_size(char *argv[]);
int ft_isspace(char *c);
int count_spaces(char *argv[]);
void ft_error(void);
#endif