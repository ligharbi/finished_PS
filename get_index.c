/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:02:14 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 23:24:34 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*av_to_tab(int n, char **av)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * (n));
	if (!tab)
		return (NULL);
	while (i < n)
	{
		tab[i] = ft_atoi(av[i]);
		i ++;
	}
	selection_sort(tab, n);
	return (tab);
}

void	flip(int *p, int *d)
{
	int	tmp;

	tmp = *p;
	*p = *d;
	*d = tmp;
}

void	selection_sort(int *tab, int n)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	while (i < n)
	{
		min_index = i;
		j = i + 1;
		while (j < n)
		{
			if (tab[j] < tab[min_index])
				min_index = j;
			j ++;
		}
		if (min_index != i)
			flip (&tab[i], &tab[min_index]);
		i++;
	}
}

int	dicotomic_search(int *tab, int n, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (tab[mid] == target)
			return (mid);
		else
		{
			if (tab[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return (-1);
}

void	assign_indexes(t_node *head, int *tab, int n)
{
	t_node	*curr;

	curr = head;
	while (curr)
	{
		curr -> index = dicotomic_search(tab, n, curr -> value);
		curr = curr -> next;
	}
}
