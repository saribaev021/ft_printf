
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

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

static	int	ft_checksp(const char *str, int index)
{
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\v' ||
	str[index] == '\f' || str[index] == '\r' || str[index] == '\n')
		index++;
	return (index);
}

static	int		ft_conv(const char *str, int *index, int l)
{
	int res;
	int k;

	res = 0;
	k = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		if (str[*index] != '0')
			k++;
		if (k > 19)
		{
			if (l > 0)
				return (0);
			else
			{
				return (-1);
			}
		}
		res = res * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (res);
}

int				ft_atoi(const char *str, int *index)
{
	int	res;
	int	minus;

	minus = 0;
	*index = ft_checksp(str, *index);
	if (str[*index] == '-')
	{
		minus++;
		(*index)++;
	}
	if (str[*index] == '+' && str[*index - 1] != '-')
		(*index)++;
	res = ft_conv(str, index, minus);
	if (minus > 0)
		res = res * -1;
	if (str[*index] == '.')
	{
		s_flags.dot = 1;
		(*index)++;
	}	
	return (res);
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

static	int			ft_putprc(const char *str, int j)
{
	int i;
	int k;

	i = 0;
	while (str[i] == '%')
		i++;
	if (j)
		return (i % 2);
	k = i / 2;
	while (k-- > 0)
		ft_putchar('%', 1);
	return (i - 1);	
}

static	void	ft_acc_str(int len, char *str)
{
	int *acc = &s_flags.acc;
	int *www = &s_flags.width;
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
	int *acc = &s_flags.acc;
	int *www = &s_flags.width;
	if (s_flags.width < 0)
	{
		s_flags.width *= -1;
		s_flags.minus = 1;
	}
	s_flags.width = (s_flags.width > len  && s_flags.dot != 1) ? s_flags.width - len : s_flags.width;
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
	int len;

	if (ptr[index] == 'c')
        str[0] = va_arg(ap, int) + '0';
    if (ptr[index] == 's')
        str = va_arg(ap, char*);
	if (ptr[index] == 's' && str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (ptr[index] == 's' || ptr[index] == 'c')
	{
		if (s_flags.width != 0)
			ft_width_str(len, str);
		else if (s_flags.acc != 0)
			ft_acc_str(len, str);
		else
			ft_putstr(str, len);
		
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

	int acc = s_flags.acc;
	int www = s_flags.width;
}

int     		ft_printf(const char *format, ...)
{
	va_list ap; 
	int i = 0;
	int flag;
	const char *ptr;

	va_start(ap, format);
	ptr = format;
	while (ptr[i] != '\0')
	{
		flag = 1;
		if (ptr[i]!= '%')
			ft_putchar(ptr[i], 1);
		else if (ptr[i++] == '%')
		{
			if (ptr[i] == '%')
			{
				flag = ft_putprc(&ptr[i - 1], 1);
				i += ft_putprc(&ptr[i - 1], 0);
			}
			if (((ptr[i] >= '0' && ptr[i] <= '9') || ptr[i] == '-' || ptr[i] == '.' || ptr[i] == '*') && flag)
				ft_flags(ptr, &i, ap);
			if (flag)
			{
				//ft_nbr(ptr, i, ap);
				//ft_print_hex_pointer(ptr, i, ap);
				ft_str(ptr, i, ap);
			}
		}
		if (!flag)
			i--;
		i++;
	}
	va_end(ap);
	return (ft_putchar('0', 0));
}
int main()
{
	//char q = "07FFFFFFFFFFFFFFF";
	 long long int w = 3223372036854775807;
	// void *ptr;
	//ptr = &w; 
	// char *name = "Канат";
	// char c  = '\n';
	// int d = 18;
	// int ii = -18;
	// int k = -12;
	// char *s = "лет";
	// unsigned int i = 123124234;
	//unsigned int w = 123124234;
	//int qw = ft_printf("%cпривет %%%%меня зовут %s, мне %d %s%cмал 16: %x%cбол 16: %X%cадрес: %p%c%i%c%d", c, name, d, s, c, i, c, i, c, &i, c, ii, c, k);
	//int wq = printf("%cпривет %%%%меня зовут %s, мне %d %s%cмал 16: %x%cбол 16: %X%cадрес: %p%c%i%c%d", c, name, d, s, c, i, c, i, c, &i, c, ii, c, k);
	//ft_printf("привет меня зовут %s%d", name, 18);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	//char *s1 = NULL;
	//char *s2 = "";
	
	//ft_printf("\n%s%d%s","Hi), my name is Kanat, i'm ", 18, " years old\n");
	//printf("%s%d%s","Hi), my name is Kanat, i'm ", 18, " years old\n");
	//printf("%s\n", s1);
	//ft_puthex('x', w);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	unsigned int u = 4234;
	char *s = NULL;
	int i = ft_printf("|%-10.2s|",  "hello");
	printf("\n");
	int k =  printf("|%-10.2s|",  "hello");
	printf("\nf %d p %d", i, k);
	return (0);
}