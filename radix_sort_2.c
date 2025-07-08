#include "push_swap.h"

void	log_move(t_context *ctx, char *move)
{
	if (!ctx -> count_moves)
		return ;
	if (ctx -> move_count >= ctx -> capacity)
	{
		ctx -> capacity *= 2;
		ctx -> moves = realloc(ctx -> moves, sizeof(char *) * ctx -> capacity);
	}
	ctx -> moves[ctx -> move_count ++] = ft_strdup(move);
	ctx -> cost ++;
}

int	get_max_bits(t_node *a)
{
	int	max_index;
	int	bits;

	max_index = 0;
	bits = 0;
	while (a)
	{
		if (a -> index > max_index)
			max_index = a -> index;
		a = a -> next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

char	**radix_sort(t_context *ctx)
{
	int	size;
	int	bits;

	size = ctx->stack->size;
	bits = get_max_bits(ctx->stack->a);
	process_bit_passes(ctx, bits, size);
	return (ctx->moves);
}

void	init_sort_ctx(t_context *ctx, t_stack *stack)
{
	ctx->stack = stack;
	ctx->count_moves = 0;
	ctx->cost = 0;
	ctx->moves = NULL;
	ctx->move_count = 0;
	ctx->capacity = 0;
}
