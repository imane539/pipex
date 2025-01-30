/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:34:34 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/12 15:29:57 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_free(char **list, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(list[i++]);
	}
	free(list);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		k;
	int		start;

	k = 0;
	i = 0;
	p = malloc((countword(s, c) + 1) * sizeof(char *));
	if (!p || !s)
		return (free(p), NULL);
	while (s[i] && k < countword(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		p[k++] = ft_substr(s, start, i - start);
		if (!p[k - 1])
			return (ft_free(p, k - 1), NULL);
	}
	p[k] = NULL;
	return (p);
}
