/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:04:00 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/03 00:02:02 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	write (fd, s, i);
	write (fd, "\n", 1);
}

void	print_moves(char **moves, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putendl_fd(moves[i], 1);
		i++;
	}
}
