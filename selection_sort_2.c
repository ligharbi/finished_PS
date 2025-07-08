#include "push_swap.h"

void	free_selection_context(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->move_count)
		free(ctx->moves[i++]);
	free(ctx->moves);
	free_stack(ctx->stack, 1);
}

int	compute_selection_cost(t_stack *original)
{
	t_context	ctx;
	int			total;

	if (!init_selection_context(&ctx, original))
		return (-1);
	selection_sort_indices(&ctx);
	total = ctx.cost;
	free_selection_context(&ctx);
	return (total);
}
