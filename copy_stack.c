/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:01:27 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 22:35:39 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*copy_list(t_node *src)
{
	t_node	*copy;
	t_node	*new;
	t_node	*last;

	copy = NULL;
	last = NULL;
	while (src)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			return (NULL);
		new -> value = src -> value;
		new -> index = src -> index;
		new -> next = NULL;
		if (!copy)
			copy = new;
		else
			last -> next = new;
		last = new;
		src = src -> next;
	}
	return (copy);
}

t_stack	*copy_t_stack(t_stack *original)
{
	t_stack	*copy;

	copy = malloc(sizeof(t_stack));
	if (!copy)
		return (NULL);
	copy -> a = copy_list(original -> a);
	copy -> b = NULL;
	copy -> size = original -> size;
	return (copy);
}
