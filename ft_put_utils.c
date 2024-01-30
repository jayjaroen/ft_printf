/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:48:57 by jjaroens          #+#    #+#             */
/*   Updated: 2024/01/30 22:19:57 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_itoa(long i, int base, int *j, char *ptr) //
{
    long num;
    char str[15];
    size_t count;

    num = (long)i; // but this is already long?
    count = 14;
    str[count] = '\0';
    if (num < 0)
        num *= -1;
    while (num / base)
    {
        // str[--count] = (num % 10) + '0';
        str[--count] = ptr[num % base];
        num /= base;
    }
    // if (num)
    str[--count] = ptr[num % base];
    //  str[--count] = (num % 10) + '0';
    if (num < 0)
        str[--count] = '-';
    ft_putstr(&str[count]);
    *j = count;
}

void ft_prefix_pointer()
{
    write (1, "0", 1);
    write (1, "x", 1);
}
