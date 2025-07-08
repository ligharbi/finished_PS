/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:11:06 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/03 01:06:09 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack -> next;
	}
	return (true);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = 0;
	i = 0;
	while (*s)
	{
		len++;
		s++;
	}
	p = malloc (len + 1);
	if (p == NULL)
		return (NULL);
	s -= len;
	while (i < len)
	{
		*p = *s;
		s++;
		p++;
		i ++;
	}
	*p = '\0';
	return (p - len);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
