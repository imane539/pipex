/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:16 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/13 13:55:21 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cmp(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	size;

	k = 0;
	j = 0;
	i = 0;
	size = ft_strlen(little);
	while (big[i] && i < len)
	{
		while (big[i] != little[j] && i < len && big[i])
			i++;
		k = i - j;
		while (big[i] == little[j] && i < len && big[i])
		{
			i++;
			j++;
		}
		if (j >= size)
			return ((char *)&big[k]);
		j--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	return (cmp(big, little, len));
}
