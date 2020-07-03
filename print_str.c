#include "ft_printf.h"

static	void	ft_acc_str(int len, char *str)
{
	//if (s_flags.acc < len && s_flags.acc > s_flags.width)
	s_flags.width = s_flags.width - s_flags.acc;
	if (s_flags.minus == 0)
	{
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
		ft_putstr(str, s_flags.acc);
	}               
	else if (s_flags.minus == 1)
	{
		ft_putstr(str, s_flags.acc);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
	else
		ft_putstr(str, s_flags.acc);
}

static	void			ft_width_str(int len, char *str)
{
	if (s_flags.width < 0)
	{
		s_flags.width *= -1;
		s_flags.minus = 1;
	}
	s_flags.width = (s_flags.width > len  && s_flags.dot != 1)? s_flags.width - len : s_flags.width;
	if (s_flags.dot == 1 && s_flags.acc < len)
		ft_acc_str(len, str);
	else if (s_flags.minus != 1)
	{
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
		ft_putstr(str, len);
	}
	else if (s_flags.minus == 1)
	{
		ft_putstr(str, len);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
}

void   ft_str(const char *ptr, int index, va_list ap)
{
	char *str;
	char c;
	int len;

	if (ptr[index] == 'c')
        c = va_arg(ap, int);
    if (ptr[index] == 's')
        str = va_arg(ap, char*);
	if (ptr[index] == 's' && str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (ptr[index] == 's')
	{
		if (s_flags.width != 0)
			ft_width_str(len, str);
		else if (s_flags.acc != 0)
			ft_acc_str(len, str);
		else
			ft_putstr(str, len);
	}
	else if (ptr[index] == 'c')
	{
		if (s_flags.width != 0)
			ft_width_str(len, "ss");
		else
			ft_putchar(c, 1);
	}
}

//email = ndreadno@ga-p1.msk.21-school.ru