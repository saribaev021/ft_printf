/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:45:00 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/02 20:05:51 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_putchar(const char c, int end)
{
	static int i = 0;

	if (end == 0)
	{
		return (i);
	}
	write(1, &c, 1);
	i++;
	return (i);
}

void		ft_putstr(char *s, size_t len)
{
	int i;

	i = 0;
	while (s[i] != '\0' && len-- > 0)
	{
		ft_putchar(s[i], 1);
		i++;
	}
}

int			ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		return ((ch - 97) + 65);
	return (ch);
}

void    ft_puthex(char flag_c, char flag_p, unsigned long int nb)
{
	const char *str = "0123456789abcdef";
	int remainder[21];
	int i;

	i = 0;
	while (nb >= 16 && i++ >= 0)
	{
		remainder[i - 1] = nb  % 16;
		nb = nb / 16;
	}
	if (flag_p == 'p')
		ft_putstr("0x", 2);
	if (flag_c != 'x')
	{
		ft_putchar(ft_toupper(str[nb]), 1);
		while (i-- > 0)
			ft_putchar(ft_toupper(str[remainder[i]]), 1);
		return ;
	}
	ft_putchar(str[nb], 1);
	while (i-- > 0)
		ft_putchar(str[remainder[i]], 1);		
}