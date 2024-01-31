/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:08:06 by jjaroens          #+#    #+#             */
/*   Updated: 2024/01/31 22:09:59 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// can use ft_putchar && ft_putstr from libft //
// but ft_putchar && ft_putstr in libft doesn't return int?
int ft_putchar(int c)
{
    return write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int count;

    if (!str)
        return (-1);
    count = 0;
    while (*str)
    {
        ft_putchar((int)*str);
        str++;
        count++;
    }
    return (count);
}

int ft_putpointer(void *p)
{
    int     count;

    count = 0;
    ft_itoa((long) p, 16, &count, HEX_LOWER);
    return (count);
}

int ft_putnum(int i)
{
    int count;

    count = 0;

    ft_itoa((long) i, 10, &count, BASE_10);
    return (count);
}

int ft_puthex(unsigned int i, char c)
{
    int count;

    count = 0;
    if (c == 'x')
        ft_itoa((long) i, 16, &count, HEX_LOWER);
    else if (c == 'X')
        ft_itoa((long) i, 16, &count, HEX_UPPER);
    return (count);
}

int ft_putunsigned(unsigned int i)
{
    int count;

    count = 0;
    ft_itoa((long) i, 10, &count, BASE_10);
    return (count);
}
