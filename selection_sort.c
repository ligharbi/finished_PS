/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:06:13 by ligharbi          #+#    #+#             */
/*   Updated: 2025/06/25 13:06:16 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_node *a)
{
	int			min;
	int			pos;
	int			i;
	t_node		*tmp;

	min = a->index;
	pos = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	rotate_min_to_top(t_context *ctx, int pos)
{
	int	j;

	j = 0;
	while (j < pos)
	{
		ra(ctx->stack);
		log_move(ctx, "ra");
		j++;
	}
}

void	push_all_to_b(t_context *ctx, int size)
{
	int	i;
	int	pos;

	i = 0;
	while (i < size)
	{
		pos = find_min_pos(ctx->stack->a);
		rotate_min_to_top(ctx, pos);
		pb(ctx->stack);
		log_move(ctx, "pb");
		i++;
	}
}

char	**selection_sort_indices(t_context *ctx)
{
	push_all_to_b(ctx, ctx->stack->size);
	while (ctx->stack->b)
	{
		pa(ctx->stack);
		log_move(ctx, "pa");
	}
	return (ctx->moves);
}

int	init_selection_context(t_context *ctx, t_stack *original)
{
	ctx->stack = copy_t_stack(original);
	if (!ctx->stack)
		return (0);
	ctx->count_moves = 1;
	ctx->cost = 0;
	ctx->move_count = 0;
	ctx->capacity = 100;
	ctx->moves = malloc(sizeof(char *) * ctx->capacity);
	if (!ctx->moves)
	{
		free_stack(ctx->stack, 1);
		return (0);
	}
	return (1);
}
