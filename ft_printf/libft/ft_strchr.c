/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:38:18 by iel-fouh          #+#    #+#             */
/*   Updated: 2025/01/16 14:38:23 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	if (!string)
		return (NULL);
	while (string[i] != (char)c && string[i])
		i++;
	if (string[i] == (char)c)
		return ((char *)&string[i]);
	return (NULL);
}
