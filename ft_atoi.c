/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:26:23 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 22:40:09 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

long long int	ft_atoi(char *nptr)
{
	long long int	r;
	int				s;

	r = 0;
	s = 1;
	while ((is_space(*nptr) == 1))
		++ nptr;
	if (is_sign(*nptr) == 1)
	{
		if (*nptr == '-')
			s = -s;
		++nptr;
	}
	while (*nptr >= '0' && *nptr <= '9' )
	{
		r = (r * 10) + (*nptr - '0');
		nptr ++;
	}
	return (r * s);
}
