/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:48:44 by marlean           #+#    #+#             */
/*   Updated: 2021/11/26 16:03:25 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_param	param_init(void)
{
	struct s_param	t_param;

	t_param.count = 0;
	t_param.x = 0;
	t_param.num = 0;
	t_param.flag_plus = 0;
	t_param.flag_space = 0;
	return (t_param);
}

static int	ft_check_one(const char **format, va_list ap)
{
	struct s_param	t_param;

	t_param = param_init();
	if (**format == 'c')
		t_param.count += ft_putchar(va_arg(ap, int));
	if (**format == ' ' || **format == '+')
		ft_space_plus(&format, &t_param.flag_plus, &t_param.flag_space);
	if (**format == 'd' || **format == 'i')
	{
		t_param.num = va_arg(ap, int);
		if (t_param.flag_plus)
			if (t_param.num >= 0)
				t_param.count += ft_putchar('+');
		if (t_param.num >= 0 && !t_param.flag_plus && t_param.flag_space)
			t_param.count += ft_putchar(' ');
		t_param.count += ft_putnbr(t_param.num);
	}
	if (**format == 's')
		t_param.count += ft_putstr(va_arg(ap, char *));
	return (t_param.count);
}

static int	ft_check_two(const char **format, va_list ap)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	if (**format == 'u')
		count += ft_unsigned(va_arg(ap, unsigned int));
	if (**format == '%')
		count += ft_putchar('%');
	if (**format == 'p')
		count += ft_point_hex(va_arg(ap, unsigned long int));
	if (**format == 'x')
		count += ft_hex(va_arg(ap, unsigned int), 1);
	if (**format == 'X')
		count += ft_hex(va_arg(ap, unsigned int), 2);
	if (**format == '#')
	{
		(*format)++;
		x = va_arg(ap, unsigned int);
		count += ft_sharp(x, **format);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;
	int		width;

	count = 0;
	width = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_check_one(&format, ap);
			count += ft_check_two(&format, ap);
			format++;
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(ap);
	return (count);
}
