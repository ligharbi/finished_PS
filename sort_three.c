#include "push_swap.h"

bool	already_sorted(t_node *a)
{
	while (a && a -> next)
	{
		if (a -> value < a -> next -> value)
			a = a -> next;
		else
			return (false);
	}
	return (true);
}

void	rest_sort_three(t_stack *s, int i)
{
	if (s -> a -> index == i + 2)
	{
		if (s -> a -> next -> index == i)
		{
			ra(s);
			write(1, "ra\n", 3);
		}
		else
		{
			ra(s);
			sa(s);
			write(1, "ra\nsa\n", 6);
		}
		return ;
	}
}

void	sort_three_part2(t_stack *s, int i)
{
	if (s -> a -> next -> index == i)
	{
		sa(s);
		write(1, "sa\n", 3);
	}
	else
	{
		rra(s);
		write(1, "rra\n", 4);
	}
}

void	sort_three(t_stack *s, int i)
{
	if (already_sorted(s -> a))
		return ;
	if (s -> a -> index == i)
	{
		rra(s);
		sa(s);
		write(1, "rra\nsa\n", 7);
		return ;
	}
	else
	{
		if (s -> a -> index == i + 1)
			return (sort_three_part2(s, i));
	}
	rest_sort_three(s, i);
}

/*
 if (s -> a -> index == i + 1)
                {
                        if (s -> a -> next -> index == i)
                        {
                                sa(s);
                                write(1, "sa\n", 3);
                        }
                        else
                        {
                                rra(s);
                                write(1, "rra\n", 4);
                        }
                        return ;*/

int	stack_len(t_node *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len ++;
		a = a -> next;
	}
	return (len);
}
