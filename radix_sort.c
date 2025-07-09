/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:04:56 by ligharbi          #+#    #+#             */
/*   Updated: 2025/06/25 13:05:00 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_current_bit(t_context *ctx, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((ctx->stack->a->index >> bit) & 1) == 0)
		{
			pb(ctx->stack);
			log_move(ctx, "pb");
		}
		else
		{
			ra(ctx->stack);
			log_move(ctx, "ra");
		}
		i++;
	}
	while (ctx->stack->b)
	{
		pa(ctx->stack);
		log_move(ctx, "pa");
	}
}

void	process_bit_passes(t_context *ctx, int bits, int size)
{
	int	i;

	i = 0;
	while (i < bits)
	{
		process_current_bit(ctx, i, size);
		i++;
	}
}

void	init_ctx(t_context *ctx, t_stack *copy)
{
	ctx->stack = copy;
	ctx->count_moves = 1;
	ctx->cost = 0;
	ctx->move_count = 0;
	ctx->capacity = 100;
	ctx->moves = malloc(sizeof(char *) * 100);
}

int	compute_radix_cost(t_stack *original)
{
	int			total;
	t_stack		*copy;
	t_context	ctx;

	copy = copy_t_stack(original);
	if (!copy)
		return (-1);
	init_ctx(&ctx, copy);
	if (!ctx.moves)
		return (-1);
	radix_sort(&ctx);
	total = ctx.cost;
	free_moves(ctx.moves, ctx.move_count);
	free_stack(ctx.stack, 1);
	return (total);
}

void	sort_with_radix(t_stack *stack)
{
	t_context	ctx;

	init_sort_ctx(&ctx, stack);
	radix_sort(&ctx);
}
