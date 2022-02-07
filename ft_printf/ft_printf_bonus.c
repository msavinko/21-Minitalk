/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:59:13 by marlean           #+#    #+#             */
/*   Updated: 2021/11/26 15:34:01 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sharp(unsigned int x, char format)
{
	int	count;

	count = 0;
	if (x == 0)
		count += ft_putchar('0');
	else if (format == 'x')
	{
		count += ft_putstr("0x");
		count += ft_hex(x, 1);
	}
	else if (format == 'X')
	{
		count += ft_putstr("0X");
		count += ft_hex(x, 2);
	}
	return (count);
}

void	ft_space_plus(const char ***format, int *flag_plus, int *flag_space)
{
	while (***format == ' ' || ***format == '+')
	{
		if (***format == '+')
			*flag_plus = 1;
		if (***format == ' ')
			*flag_space = 1;
		(**format)++;
	}
}
