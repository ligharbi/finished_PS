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

void	push_swap(int ac, char **av, t_stack *s, int *sorted_tab)
{
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
}

int	main(int ac, char **av)
{
	t_stack	*s;
	int		*sorted_tab;

	s = NULL;
	sorted_tab = NULL;
	if (ac < 2)
		return (0);
	ac --;
	av ++;
	if (ac == 1)
	{
		ac = count_words(av[0]);
		av = ft_split(av[0]);
	}
	verif_input(av, ac);
	push_swap(ac, av, s, sorted_tab);
	free_stack(s, 1);
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_stack	*s;
	int		*sorted_tab;

	if(ac < 2)
		return (0);
	av ++;
	ac --;
	if(ac == 1)
	{
		ac = count_words(av[0]);
		av = ft_split(av[0]);
	}
	verif_input(av, ac);
	s = malloc(sizeof (t_stack));
	if (!s)
		return(1);
	s->a = iniz_stack(av, ac);
	s->b = NULL;
	s->size = ac;
	sorted_tab = av_to_tab(ac, av);
	assign_indexes(s -> a, sorted_tab, ac);
	if(!is_sorted(s -> a))
		if (ac == 3)
			sort_three(s);
        else 
		{
			if (ac == 5)
            	sort_five(s);
        	else
            	best_sort(s);
		}
    free_stack(s, 1);
    return (0);
}
*/
