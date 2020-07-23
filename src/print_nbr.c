/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:08:19 by ndreadno          #+#    #+#             */
/*   Updated: 2020/07/09 23:32:33 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static long long int	ft_len_nb(long long int n)
{
	unsigned long long int	nb;
	int						i;

	i = 0;
	nb = n;
	if (n < 0)
		nb = (unsigned long long int)-n;
	if (n == 0)
		i++;
	while (nb > 0 && i++ >= 0)
		nb = nb / 10;
	return (i);
}

void					ft_putnbr(long long int n)
{
	unsigned long long int nb;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0', 1);
	}
	else if (n < 0)
	{
		nb = (unsigned long long int)-n;
		ft_putchar('-', 1);
		ft_putnbr(nb);
	}
	else
	{
		ft_putchar(n % 10 + 48, 1);
	}
}

void					ft_nbr(const char *ptr, int index, va_list ap)
{
	long long int	d;
	int				len;

	d = 0;
	if (ptr[index] == 'd' || ptr[index] == 'i')
	{
		d = va_arg(ap, int);
	}
	if (ptr[index] == 'u')
	{
		d = va_arg(ap, unsigned int);
	}
	len = ft_len_nb(d);
	if (ptr[index] == 'u' || ptr[index] == 'd' || ptr[index] == 'i')
	{
		if (s_fg.wid != 0)
			ft_width_y(len, &d, ptr[index]);
		else if (s_fg.acc != 0 && s_fg.acc > len)
			ft_acc_y(len, 0, &d, ptr[index]);
		else if (s_fg.dot == 1 && s_fg.acc == 0)
			return ;
		else
			ft_putnbr(d);
	}
}
