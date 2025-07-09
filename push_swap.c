/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:48:19 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/03 01:24:48 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_swap(int ac, char **av, int *sorted_tab, bool need_free)
{
	t_stack	*s;

	s = malloc(sizeof (t_stack));
	s -> a = iniz_stack(av, ac);
	s -> b = NULL;
	s -> size = ac;
	sorted_tab = av_to_tab(ac, av);
	assign_indexes(s -> a, sorted_tab, ac);
	if (!is_sorted(s -> a))
	{
		if (ac == 3)
			sort_three(s, 0);
		else
		{
			if (ac == 5)
				sort_five(s);
			else
				best_sort(s);
		}
	}
	if (need_free)
		free_split(av);
	free(sorted_tab);
	free_stack(s, 1);
}

int	main(int ac, char **av)
{
	bool	need_free;
	int		*sorted_tab;

	need_free = false;
	sorted_tab = NULL;
	if (ac < 2)
		return (0);
	ac --;
	av ++;
	if (ac == 1)
	{
		ac = count_words(av[0]);
		av = ft_split(av[0]);
		need_free = true;
	}
	verif_input(av, ac);
	push_swap(ac, av, sorted_tab, need_free);
	return (0);
}
