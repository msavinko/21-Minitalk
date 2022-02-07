/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:05:46 by marlean           #+#    #+#             */
/*   Updated: 2022/01/18 17:07:29 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recurs_hex(unsigned long int p, int letters)
{
	if (p < 16)
	{
		if (p % 16 <= 9)
			ft_putchar(p + '0');
		else
			ft_putchar(p + letters);
	}
	else
	{	
		ft_recurs_hex(p / 16, letters);
		ft_recurs_hex(p % 16, letters);
	}
}

int	ft_hex(unsigned int p, int flag)
{
	if (!p)
	{
		ft_putchar('0');
		return (1);
	}
	if (flag == 1)
		ft_recurs_hex(p, 'a' - 10);
	else if (flag == 2)
		ft_recurs_hex(p, 'A' - 10);
	return (ft_nbrlen(p, 16));
}

int	ft_point_hex(unsigned long int p)
{
	if (!p)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	ft_recurs_hex(p, 'a' - 10);
	return (ft_nbrlen(p, 16) + 2);
}
