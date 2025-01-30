/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:18:31 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/11/15 21:44:11 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(const char *format, va_list args);
int	ft_check(char c, va_list args);
int	ft_putunsigned(unsigned int n, int fd);
int	ft_easy(char c, va_list args);
int	ft_medium(char c, va_list args);
int	ft_hard(va_list args);
int	ft_hex(unsigned int nb, char c);
int	ft_address(unsigned long nb);

#endif