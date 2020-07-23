/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:27:16 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/09 23:32:24 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

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
