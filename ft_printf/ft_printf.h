/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:09:18 by marlean           #+#    #+#             */
/*   Updated: 2021/11/26 15:48:55 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_param
{
	int				count;
	unsigned int	x;
	int				num;
	int				flag_plus;
	int				flag_space;
}	t_param;

int		ft_printf(const char *format, ...);

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_nbrlen(unsigned long int nb, int dec);
int		ft_putnbr(int n);
int		ft_unsigned(unsigned int nb);
int		ft_hex(unsigned int p, int flag);
int		ft_point_hex(unsigned long int p);
int		ft_sharp(unsigned int x, char format);
void	ft_space_plus(const char ***format, int *flag_plus, int *flag_space);

#endif