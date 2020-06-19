/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:38:43 by ndreadno          #+#    #+#             */
/*   Updated: 2020/06/19 19:42:38 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int     ft_printf(const char *format, ...)
{
    va_list factor; 
    int d;
    char c;
    char *s;
    const char *ptr;

    va_start(factor, format);
    ptr = format;
    //printf("%s", ptr);
    while (*ptr != '\0')
    {
        if(*ptr != '%')
        {
            write(1, &*ptr, 1);
            *ptr++;
            continue;
        }
        if (*++ptr == 'd')
        {
            d = va_arg(factor, int);
            printf("%d", d);
            *ptr++;
            continue;
        }
        if (*ptr == 'c')
        {
            c = va_arg(factor, int);
            printf("%c", c);
            *ptr++;
            continue;
        }
        if (*ptr == 's')
        {
            s = va_arg(factor, char*);
            printf("%s", s);
            *ptr++;
            continue;
        }
    }
    va_end(factor);
}
int main()
{
    char *name = "Канат";
    char c  = '\n';
    int d = 18;
    char *s = "лет";
    ft_printf("привет меня зовут %s, мне %d %s%c", name, d, s, c);
    //printf("привет меня зовут %s, мне %d %s%c", name, d, s, c);
    
    return (0);
}