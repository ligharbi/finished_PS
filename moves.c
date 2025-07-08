/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:54:28 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 23:49:13 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap(t_node *stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (stack && stack->next)
	{
		tmp_val = stack->value;
		tmp_idx = stack->index;
		stack->value = stack->next->value;
		stack->index = stack->next->index;
		stack->next->value = tmp_val;
		stack->next->index = tmp_idx;
	}
	return (stack);
}

void	sa(t_stack *stack)
{
	if (stack)
		swap(stack->a);
}

void	sb(t_stack *stack)
{
	if (stack)
		swap(stack->b);
}

void	ss(t_stack *stack)
{
	if (stack)
	{
		swap(stack->a);
		swap(stack->b);
	}
}

void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack && stack -> b)
	{
		tmp = stack -> b;
		stack -> b = stack -> b -> next;
		tmp -> next = stack -> a;
		stack -> a = tmp;
	}
}
