/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:22:41 by jjaroens          #+#    #+#             */
/*   Updated: 2024/01/21 17:48:02 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
//The number of char read in the standard output
//The pointer of the argument to the list
//Macro in varadic function

int print_address(void *p)
{
 // To implement the function   
}

int print_char(int c)
{   
    return write(1, &c, 1);
}

int print_str(char *str)
{
    int count;
    
    count = 0;
    while (*str)
    {
        print_char((int)*str);
        str++;
        count++;
    }
    return (count);
}

int ft_format(char spec, va_list ap)
{
    int count;
    
    count = 0;
    if (spec == 'c')
        count += print_char(va_arg(ap, int));
    else if (spec == 's')
        count += print_str(va_arg(ap, char *));
    else if (spec == 'd')
        count += print_num(va_arg(ap, int));
    else if (spec == 'p')
        count += print_address(va_arg(ap, void *));
    //write print_f for hexademimal && digit
    return (count);
}

int	ft_printf(const char *args, ...) 
{
    va_list ap; //argument pointer --> standard naming for va_list // already a pointer
    va_start(ap, args);
    int count;
    
    count = 0;
    while (*args != '\0') // how to know for this?
    {
        if (*args == '%')
            count += ft_format(*(++args), ap);
        else
            count += write(1, args, 1);
        args++;   
    }
    va_end(ap);
    return (count);
}

int main(void)
{
    ft_printf("The result of MY print f: %s\n", "hahaha");
    printf("The result of print f: %s\n", "hahaha");
}
