/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:54:15 by jjaroens          #+#    #+#             */
/*   Updated: 2024/01/28 15:55:22 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
#define HEX_UPPER "0123456789ABCDEF"
#define HEX_LOWER "0123456789abcdef"

// variadic function && macro
#include <stdarg.h>
#include <unistd.h>
int	ft_printf(const char *args, ...);
void ft_itoa(long i, int base, int *j, char *str);
int ft_putstr(char *str);
#endif
