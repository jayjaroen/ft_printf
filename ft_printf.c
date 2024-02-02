/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:22:41 by jjaroens          #+#    #+#             */
/*   Updated: 2024/02/02 22:41:41 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
//The number of char read in the standard output
//The pointer of the argument to the list
//Macro in varadic function
//pointer printout prefix

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
    {
        count += write(1, "0x", 2);
        count += ft_putpointer(va_arg(ap, void *));
    }
    else if (spec == 'i' || spec == 'd')
        count += ft_putnum(va_arg(ap, int));
    else if (spec == 'u')
        count += ft_putunsigned(va_arg(ap, unsigned int));
    else if (spec == 'x' || spec == 'X')
        count += ft_puthex(va_arg(ap, int), spec);
    return (count);
}
// main function
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

/*int main(void)
{
    // int *i = NULL;

    ft_printf("The result of MY print f: %s\n", "hahaha");
    printf("The result of print f: %s\n", "hahaha");
    // printf("pointer address: %p\n", i); //234234353
    // // // printf("unsigned long: %p\n", (void *)(i));
    // ft_printf("my function pointer address: %p\n", i);
    // printf("the return: %i\n", printf("%p", i));
    // ft_printf("the return: %i\n", ft_printf("%p",i));
    // // ft_printf("%%\n");
    // printf("%d\n", 000);
    // ft_printf("%d\n", 000);
    // printf("%x\n", -1);
    // check the return of printf function
    // printf("the return of printf function: %i\n", printf("12344\n"));
    // ft_printf("the return of my printf function: %i\n", ft_printf("12344\n"));
    // printf("lower case: %x\n", 1234522222);
    // printf("upper case: %X\n", 1234522222);
    // ft_printf("my print f lower case: %x\n", 1234522222);
    // ft_printf("my print f uppwer case: %X\n", 1234522222);
    // printf("printf unsigned int: %u\n", -12345);
    // ft_printf("my printf unsiged int: %u\n", -12345);
    // printf("");
    // ft_printf("");
}*/
