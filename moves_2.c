#include "push_swap.h"

void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack && stack -> a)
	{
		tmp = stack -> a;
		stack -> a = stack -> a ->next;
		tmp -> next = stack -> b;
		stack -> b = tmp;
	}
}

void	ra(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack && stack -> a && stack -> a -> next)
	{
		first = stack -> a;
		stack -> a = stack -> a -> next;
		last = stack -> a;
		while (last -> next)
			last = last -> next;
		last -> next = first;
		first -> next = NULL;
	}
}

void	rb(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack && stack -> b && stack -> b -> next)
	{
		first = stack -> b;
		stack -> b = stack -> b -> next;
		last = stack -> b;
		while (last -> next)
			last = last -> next;
		last -> next = first;
		first -> next = NULL;
	}
}

void	rra(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack -> a || !stack -> a -> next)
		return ;
	prev = NULL;
	last = stack -> a;
	while (last -> next)
	{
		prev = last;
		last = last -> next;
	}
	prev -> next = NULL;
	last -> next = stack -> a;
	stack -> a = last;
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !stack -> b || !stack -> b -> next)
		return ;
	prev = NULL;
	last = stack -> b;
	while (last->next)
	{
		prev = last;
		last = last -> next;
	}
	prev -> next = NULL;
	last -> next = stack -> b;
	stack -> b = last;
}
