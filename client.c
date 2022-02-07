/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:40:40 by marlean           #+#    #+#             */
/*   Updated: 2022/01/21 12:23:32 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_mini_atoi(const char *str)
{
	int			i;
	long int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > 2147483647)
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	return ((int)num);
}

static void	ft_send_string(char *str, int pid)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(700);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(700);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_mini_atoi(argv[1]);
		if (pid != 0)
			ft_send_string(argv[2], pid);
		else
			ft_printf("Wrong PID");
	}
	else
		ft_printf("Wrong input, please try again\n");
	return (0);
}
