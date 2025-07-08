/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:36:47 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 22:38:45 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node -> next;
		free (node);
		node = tmp;
	}
}

void	free_stack(t_stack *stack, int free_struct)
{
	if (!stack)
		return ;
	free_list(stack -> a);
	free_list(stack -> b);
	if (free_struct)
		free(stack);
}
