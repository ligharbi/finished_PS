/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:41:20 by ligharbi          #+#    #+#             */
/*   Updated: 2025/07/02 22:42:15 by ligharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s)
{
	int	n;

	n = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s == ' ' || *s == '\t')
			s++;
		else
		{
			n++;
			while (*s != '\0' && *s != ' ' && *s != '\t')
				s++;
		}
	}
	return (n);
}

char	*first_word(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (*str == '\0')
		return (NULL);
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	result = malloc (i + 1);
	if (result == NULL)
		return (NULL);
	while (j < i)
	{
		result[j] = str[j];
		j ++;
	}
	result[j] = '\0';
	return (result);
}

char	*move_me(char *s, int i)
{
	if (i == 0)
	{
		while (*s == ' ' || *s == '\t')
			s++;
	}
	else
	{
		if (i == 1)
		{
			while (*s != ' ' && *s != '\t' && *s != '\0')
				s ++;
		}
	}
	return (s);
}

char	**sp0_free(int n, char **m, int i)
{
	char	**r;

	if (n == 0)
	{
		r = malloc (sizeof(char *));
		if (r == NULL)
			return (NULL);
		r [0] = NULL;
		return (r);
	}
	else
	{
		while (i > 0)
		{
			free (m [i - 1]);
			i --;
		}
		free (m);
		return (NULL);
	}
}

char	**ft_split(char *s)
{
	int		nb_words;
	int		i;
	char	*str;
	char	**matrice;

	nb_words = count_words(s);
	i = 0;
	matrice = NULL;
	str = (char *)s;
	if (nb_words == 0)
		return (sp0_free(nb_words, matrice, i));
	matrice = malloc (sizeof(char *) * (nb_words + 1));
	if (matrice == NULL)
		return (NULL);
	while (nb_words > i)
	{
		str = move_me(str, 0);
		matrice [i] = first_word(str);
		if (matrice [i] == NULL)
			return (sp0_free(nb_words, matrice, i));
		str = move_me(str, 1);
		i ++;
	}
	matrice [i] = NULL;
	return (matrice);
}
