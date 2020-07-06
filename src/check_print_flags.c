/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:50:58 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/06 20:17:20 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"


void	ft_print(int len, void *var, char flag)
{
	if (flag == 'x')
		ft_puthex('x', 'x', *((unsigned int *)var));
	else if (flag == 'X')
		ft_puthex('X', 'X', *((unsigned int *)var));
	else if (flag == 'p')
		ft_puthex('x', 'p', *((unsigned long int *)var));
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(*((int *)var));
	else if (flag == 'u')
		ft_putnbr(*((unsigned int*)var));
	else if (flag == 's')
		ft_putstr(((char *)var), len);
	else
		ft_putchar(*((int *)var), 1);
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
		ft_print(0, var, flag);
	}
	else if (s_flags.acc > len && s_flags.acc < s_flags.width && s_flags.minus == 1)
	{
		while ((s_flags.acc-- - len) > 0)
			ft_putchar('0', 1);
		ft_print(0, var, flag);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
	else if (s_flags.acc > len && s_flags.acc > s_flags.width)
	{
		while ((s_flags.acc-- - len) > 0)
			ft_putchar('0', 1);
		ft_print(0, var, flag);
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
		ft_print(0, var, flag);
	}
	else if (s_flags.minus == 1)
	{
		ft_print(0, var, flag);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
}

static	void	ft_flag_star(const char *ptr, int *index, va_list ap)
{
	if (ptr[*index] == '*')
	{
		if (s_flags.dot != 1)
		{
			s_flags.width = va_arg(ap, int);
			s_flags.star_width = 1;
		}
		if (s_flags.dot == 1)
		{
			s_flags.acc = va_arg(ap, int);
			s_flags.star_acc = 1;
		}
		(*index)++;
		if (ptr[*index] == '.')
		{
			s_flags.dot = 1;
			(*index)++;
			if (ptr[*index] == '*')
				ft_flag_star(ptr, index, ap);
		}
	}
}

void			ft_flags(const char *ptr, int *index, va_list ap)
{
		//int *acc = &s_flags.acc;
	//int *www = &s_flags.width;
	s_flags.dot = 0;
	s_flags.minus = 0;
	s_flags.zero = 0;
	s_flags.width = 0;
	s_flags.acc = 0;
	s_flags.star_acc = 0;
	s_flags.star_width = 0;
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
	ft_flag_star(ptr, index, ap);
	s_flags.width = (s_flags.dot != 1 && s_flags.star_width != 1) ? ft_atoi(ptr, index) : s_flags.width;
	ft_flag_star(ptr, index, ap);
	s_flags.acc = (s_flags.dot == 1 && s_flags.star_acc != 1) ? ft_atoi(ptr, index) : s_flags.acc;
	s_flags.acc = (s_flags.dot != 1 && s_flags.zero == 1 && s_flags.minus != 1) ? s_flags.width : s_flags.acc;
	s_flags.width = (s_flags.acc == s_flags.width && s_flags.zero == 1) ? 0 : s_flags.width;
}