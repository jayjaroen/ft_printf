/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:08:06 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/03 16:29:54 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *p)
{
	int	count;

	count = 0;
	ft_printpointer((unsigned long)p, 16, &count, HEX_LOWER);
	if (count == 0)
		return (-1);
	return (count);
}

int	ft_putnum(int i)
{
	int	count;

	count = 0;
	ft_itoa((long) i, 10, &count, BASE_10);
	if (count == 0)
		return (-1);
	return (count);
}

int	ft_puthex(unsigned int i, char c)
{
	int	count;

	count = 0;
	if (c == 'x')
		ft_itoa((long) i, 16, &count, HEX_LOWER);
	else if (c == 'X')
		ft_itoa((long) i, 16, &count, HEX_UPPER);
	if (count == 0)
		return (-1);
	return (count);
}

int	ft_putunsigned(unsigned int i)
{
	int	count;

	count = 0;
	ft_itoa((long) i, 10, &count, BASE_10);
	if (count == 0)
		return (-1);
	return (count);
}
