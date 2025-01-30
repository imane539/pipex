/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:51:14 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/11 16:22:13 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	char	*j;

	j = NULL;
	i = 0;
	while (string[i])
	{
		if (string[i] == (char)c)
			j = (char *)&string[i];
		i++;
	}
	if (string[i] == (char)c)
		j = (char *)&string[i];
	return (j);
}
