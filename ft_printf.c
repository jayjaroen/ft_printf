/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:22:41 by jjaroens          #+#    #+#             */
/*   Updated: 2024/01/28 16:00:45 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
//The number of char read in the standard output
//The pointer of the argument to the list
//Macro in varadic function
//pointer printout prefix

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
    // To implement the function
    int     count;


 
    ft_itoa((long) p, 16, &count, HEX_LOWER);
 //putnumber based - text
 //print prefix 
 //hexideximal 
    return (count);
}

int ft_putnum(int i)
{
    int count;
    
    count = 0;
    
    ft_itoa((long) i, 10, &count, HEX_LOWER);
    return(count);
}

int ft_puthex(unsigned int i)
{
    int count;
    
    count = 0;
    return(count);
}

int ft_format(char spec, va_list ap)
{
    int count;

    count = 0;
    if (spec == 'c')
        count += ft_putchar(va_arg(ap, int));
    else if (spec == 's')
        count += ft_putstr(va_arg(ap, char *));
    else if (spec == '%') //how to print the sign out
        count += ft_putchar('%');
    else if (spec == 'p')
        count += ft_putpointer(va_arg(ap, void *));
    else if (spec == 'i' || spec == 'd')
        count += ft_putnum(va_arg(ap, int));
    else if (spec == 'x' || spec == 'X')
        count += ft_puthex(va_arg(ap, int));
    //write print_f for hexademimal && digit
    //also "u" // unsigned 
    return (count);
}

int	ft_printf(const char *args, ...)
{
    va_list ap; //argument pointer --> standard naming for va_list // already a pointer // storting address // list of the address
    va_start(ap, args);
    int count;

    if (!args)
        return (-1);
    count = 0;
    while (*args != '\0') // how to know for this?
    {
        if (*args == '%')
            count += ft_format(*(++args), ap);
        // if (*args == '%' && *(args + 1) == '%')
        //     count += write(1, "%", 1);
        else
            count += write(1, args, 1);
        args++;
    }
    va_end(ap);
    return (count);
}

int main(void)
{
    int *i;

    // ft_printf("The result of MY print f: %s\n", "hahaha");
    // printf("The result of print f: %s\n", "hahaha");
    printf("pointer address: %p\n", i); //234234353
    // printf("unsigned long: %p\n", (void *)(i));
    ft_printf("my function pointer address: %p\n", i);
    ft_printf("%%\n");
    printf("%d\n", 123456789);
    ft_printf("%d\n", 123456789);
    printf("%x\n", -1);
}
