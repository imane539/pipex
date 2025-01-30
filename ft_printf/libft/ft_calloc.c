/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:46:54 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/11 16:09:46 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	s;

	s = count * size;
	if (count && s / count != size)
		return (NULL);
	p = malloc(s);
	if (!p)
		return (NULL);
	ft_bzero(p, s);
	return (p);
}
