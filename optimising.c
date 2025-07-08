/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimising.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:03:33 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 23:56:58 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_move_count(t_stack *stack)
{
	t_stack	*copy;
	int		cost_slc;
	int		cost_rdx;

	copy = copy_t_stack(stack);
	if (!copy)
		return (-1);
	cost_slc = compute_selection_cost(copy);
	free_stack(copy, 1);
	copy = copy_t_stack(stack);
	if (!copy)
		return (-1);
	cost_rdx = compute_radix_cost(copy);
	free_stack(copy, 1);
	if (cost_slc < 0 || cost_rdx < 0)
		return (-1);
	if (cost_slc <= cost_rdx)
		return (cost_slc);
	return (cost_rdx);
}

t_context	init_context(t_stack *stack, int move_count, char **moves_buffer)
{
	t_context	ctx;

	ctx.stack = stack;
	ctx.count_moves = 1;
	ctx.cost = 0;
	ctx.move_count = 0;
	ctx.capacity = move_count;
	ctx.moves = moves_buffer;
	return (ctx);
}

int	get_better_sort(t_stack *stack, t_context *ctx)
{
	int		sel_cost;
	int		rdx_cost;
	t_stack	*copy;

	copy = copy_t_stack(stack);
	if (!copy)
		return (-1);
	sel_cost = compute_selection_cost(copy);
	free_stack(copy, 1);
	copy = copy_t_stack(stack);
	if (!copy)
		return (-1);
	rdx_cost = compute_radix_cost(copy);
	free_stack(copy, 1);
	if (sel_cost <= rdx_cost)
	{
		selection_sort_indices(ctx);
		return (0);
	}
	radix_sort(ctx);
	return (0);
}

void	best_sort(t_stack *stack)
{
	int			move_count;
	int			i;
	char		**moves_buffer;
	t_context	ctx;

	move_count = get_best_move_count(stack);
	if (move_count < 0)
		return ;
	moves_buffer = malloc(sizeof(char *) * move_count);
	if (!moves_buffer)
		return ;
	ctx = init_context(stack, move_count, moves_buffer);
	if (get_better_sort(stack, &ctx) == -1)
		return ;
	print_moves(ctx.moves, ctx.move_count);
	i = 0;
	while (i < ctx.move_count)
		free(ctx.moves[i++]);
	free(ctx.moves);
}
