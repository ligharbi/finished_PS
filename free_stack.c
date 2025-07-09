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

void	free_stack(t_stack *stack, int free_struct)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack -> a)
	{
		tmp = stack -> a;
		stack -> a = stack -> a -> next;
		free(tmp);
	}
	while (stack -> b)
	{
		tmp = stack -> b;
		stack -> b = stack -> b -> next;
		free(tmp);
	}
	if (free_struct && stack)
		free (stack);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i ++;
	}
	free(split);
}

void	free_moves(char **moves, int count)
{
	int	i;

	i = 0;
	if (!moves)
		return ;
	while (i < count)
	{
		free(moves[i]);
		i ++;
	}
	free(moves);
}
