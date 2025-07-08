/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:50:46 by ligharbi          #+#    #+#             */
/*   Updated: 2025/06/19 08:51:43 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	append_node(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = new;
	}
}

t_node	*iniz_stack(char **s, int n)
{
	t_node	*head;
	t_node	*new;
	int		i;

	head = NULL;
	i = 0;
	while (i < n)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			return (NULL);
		new -> value = ft_atoi (s[i]);
		new -> index = -1;
		new -> next = NULL;
		append_node (&head, new);
		i++;
	}
	return (head);
}
