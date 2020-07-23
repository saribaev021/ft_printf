/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:55:22 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/09 23:32:30 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static unsigned long int	ft_len_xex(unsigned long int nb)
{
	int i;

	i = 0;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i + 1);
}

static void					spec_p(unsigned long x, int len)
{
	if (s_fg.wid != 0)
		ft_width_y(len + 2, &x, 'p');
	else if (s_fg.acc != 0 && s_fg.acc > len)
		ft_acc_y(len + 2, 0, &x, 'p');
	else
		ft_puthex('x', 'p', x);
}

void						ft_h_p(const char *ptr, int index, va_list ap)
{
	unsigned long int	x;
	int					len;

	x = 0;
	if (ptr[index] == 'x' || ptr[index] == 'X')
		x = va_arg(ap, unsigned int);
	if (ptr[index] == 'p')
		x = va_arg(ap, unsigned long int);
	len = ft_len_xex(x);
	if (ptr[index] == 'x' || ptr[index] == 'X')
	{
		if (s_fg.wid != 0)
			ft_width_y(len, &x, ptr[index]);
		else if (s_fg.acc != 0 && s_fg.acc > len)
			ft_acc_y(len, 0, &x, ptr[index]);
		else if (s_fg.dot == 1 && s_fg.acc == 0)
			return ;
		else
			ft_puthex(ptr[index], 'x', x);
	}
	if (ptr[index] == 'p')
		spec_p(x, len);
}
