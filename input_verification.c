/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:49:24 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 23:34:02 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	duplicate(char *s, int n, char **arg)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (ft_strcmp(s, arg[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

bool	dup_int(char **arg, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < n -1)
	{
		while (j < n)
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				return (true);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (false);
}

bool	check_input(char **s, int c)
{
	int	i;

	i = 0;
	while (s[i] && c > i)
	{
		if (!is_digit(s[i]) || (duplicate(s[i], i, s)) || dup_int(s, c)
			|| ft_atoi(s[i]) > INT_MAX || ft_atoi(s[i]) < INT_MIN)
			return (false);
		i ++;
	}
	return (true);
}

void	verif_input(char **s, int c)
{
	if (!check_input(s, c))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
