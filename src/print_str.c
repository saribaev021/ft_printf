#include "header/ft_printf.h"

static	void	ft_acc_str(int len, char *var, char flag)
{
	int *acc = &s_flags.acc;
	int *www = &s_flags.width;
	s_flags.width = s_flags.acc < len ? s_flags.width - s_flags.acc : s_flags.width - len;
	if (s_flags.minus == 0)
	{
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
		ft_print(s_flags.acc, var, flag);
	}               
	else if (s_flags.minus == 1)
	{
		ft_print(s_flags.acc, var, flag);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
	else
		ft_print(s_flags.acc, var, flag);
}

static	void			ft_width_str(int len, void *var, char flag)
{
	if (s_flags.width < 0)
	{
		s_flags.width *= -1;
		s_flags.minus = 1;
	}
	int *acc = &s_flags.acc;
	int *www = &s_flags.width;
	s_flags.width = (s_flags.dot != 1)? s_flags.width - len : s_flags.width;
	if (s_flags.dot == 1)
		ft_acc_str(len, var, flag);
	else if (s_flags.minus != 1)
	{
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
		ft_print(len, var, flag);
	}
	else if (s_flags.minus == 1)
	{
		ft_print(len, var, flag);
		while (s_flags.width-- > 0)
			ft_putchar(' ', 1);
	}
}

static	void	ft_char_prc(char c)
{
	if (s_flags.width != 0)
		ft_width_y(1, &c, 'c');
	else if (s_flags.acc != 0)
		ft_acc_y(1,&c, 'c');
	else
		ft_putchar(c, 1);
}
static	void	ft_s(char *str, int len)
{
	if (s_flags.width != 0)
		ft_width_str(len, str, 's');
	else if (s_flags.acc > 0)
		ft_acc_str(len, str, 's');
	else if (s_flags.acc == 0 && s_flags.dot == 1)
		return;
	else
		ft_putstr(str, len);
}

void   ft_str(const char *ptr, int index, va_list ap)
{
	char *str;
	char c;
	size_t len;

	c = '%';
	str = "";
	if (ptr[index] == 'c')
        c = va_arg(ap, int);
    if (ptr[index] == 's')
        str = va_arg(ap, char*);
	if (ptr[index] == 's' && str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (ptr[index] == 's')
		ft_s(str, len);
	else if (ptr[index] == 'c' || ptr[index] == '%')
		ft_char_prc(c);
}
