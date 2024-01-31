/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:48:57 by jjaroens          #+#    #+#             */
/*   Updated: 2024/01/31 21:20:56 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_itoa(long num, int base, int *count, char *ptr) //
{
    // long i;
    char str[15];
    size_t j;
    size_t p;

    // i = (long)num; // but this is already long?
    j = 14;
    p = j;
    str[j] = '\0';
    if (num < 0)
        num *= -1;
    while (num / base)
    {
        // str[--count] = (num % 10) + '0';
        str[--j] = ptr[num % base];
        num /= base;
    }
    // if (num)
    str[--j] = ptr[num % base];
    //  str[--count] = (num % 10) + '0';
    if (num < 0)
        str[--j] = '-';
    ft_putstr(&str[j]);
    *count = p - j;
}
