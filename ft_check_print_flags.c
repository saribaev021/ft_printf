/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_print_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:50:58 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/02 16:46:49 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_print(void *var, char flag)
{
	if (flag == 'x')
		ft_puthex('x', 'x', *((unsigned int *)var));
	else if (flag == 'X')
		ft_puthex('X', 'X', *((unsigned int *)var));
	else if (flag == 'p')
		ft_puthex('x', 'p', *((unsigned long int *)var));
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(*((int *)var));
	else
		ft_putnbr(*((unsigned int*)var));
}

void	ft_acc_y(int len, void *var, char flag)
{
	s_flags.width = s_flags.width - (s_flags.acc - len);
	if (s_flags.acc > len && s_flags.acc < s_flags.width && s_flags.minus == 0)
	{
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
		while ((s_flags.acc-- - len) > 0)
			ft_putchar('0', 1);
		ft_print(var, flag);
	}
	else if (s_flags.acc > len && s_flags.acc < s_flags.width && s_flags.minus == 1)
	{
		while ((s_flags.acc-- - len) > 0)
			ft_putchar('0', 1);
		ft_print(var, flag);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
	else if (s_flags.acc > len && s_flags.acc > s_flags.width)
	{
		while ((s_flags.acc-- - len) > 0)
			ft_putchar('0', 1);
		ft_print(var, flag);
	}
}

void			ft_width_y(int len, void *var, char flag)
{
	if (s_flags.width < 0)
	{
		s_flags.width *= -1;
		s_flags.minus = 1;
	}
	s_flags.width = s_flags.width > len ? s_flags.width - len : 0;
	if (s_flags.dot == 1 && s_flags.acc > len)
		ft_acc_y(len, var, flag);
	else if (s_flags.minus != 1)
	{
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
		ft_print(var, flag);
	}
	else if (s_flags.minus == 1)
	{
		ft_print(var, flag);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
}

void			ft_flags(const char *ptr, int *index, va_list ap)
{
	s_flags.dot = 0;
	s_flags.minus = 0;
	s_flags.zero = 0;
	while (ptr[*index] == '-' || ptr[*index] == '0' || ptr[*index] == '.')
	{
		if (ptr[*index] == '-')
			s_flags.minus = 1;
		if (ptr[*index] == '0')
			s_flags.zero = 1;
		if (ptr[*index] == '.')
			s_flags.dot = 1;
		(*index)++;
	}
	if (ptr[*index] == '*')
	{
		s_flags.width = (ptr[*index] == '*' && s_flags.dot != 1) ? va_arg(ap, int) : 0;
		s_flags.acc = (ptr[*index] == '*' && s_flags.dot == 1) ? va_arg(ap, int) : 0;
		(*index)++;
		return ;
	}
	s_flags.width = s_flags.dot != 1 ? ft_atoi(ptr, index) : 0;
	s_flags.acc = s_flags.dot == 1 ? ft_atoi(ptr, index) : 0;
	s_flags.acc = (s_flags.dot != 1 && s_flags.zero == 1) ? s_flags.width : s_flags.acc;
	s_flags.width = (s_flags.acc == s_flags.width && s_flags.zero == 1) ? 0 : s_flags.width;
}