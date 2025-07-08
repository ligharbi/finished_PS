#include "push_swap.h"

int	find_index_pos(t_node *a, int index)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a -> index == index)
			return (pos);
		pos++;
		a = a -> next;
	}
	return (-1);
}

void	rotate_to_top(t_stack *s, int pos, int len)
{
	int	i;

	if (pos <= len / 2)
	{
		i = 0;
		while (i < pos)
		{
			ra(s);
			write(1, "ra\n", 3);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len - pos)
		{
			rra(s);
			write(1, "rra\n", 4);
			i++;
		}
	}
}

void	push_smallests_to_b(t_stack *s, int count, int min)
{
	int	pos;
	int	len;

	while (count > 0)
	{
		len = stack_len(s->a);
		pos = find_index_pos(s->a, min);
		rotate_to_top(s, pos, len);
		pb(s);
		write(1, "pb\n", 3);
		min++;
		count--;
	}
}

void	sort_five(t_stack *s)
{
	push_smallests_to_b(s, 2, 0);
	sort_three(s, 2);
	if (s -> b && s -> b -> next && s -> b -> index < s -> b -> next -> index)
	{
		sb(s);
		write(1, "sb\n", 3);
	}
	pa(s);
	write(1, "pa\n", 3);
	pa(s);
	write(1, "pa\n", 3);
}
