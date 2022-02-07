/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:25:45 by marlean           #+#    #+#             */
/*   Updated: 2022/01/21 12:19:28 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

static void	ft_actclient(int sigclient, siginfo_t *clientinfo, void *ccontext)
{
	static int	count_signals = 0;

	(void)ccontext;
	(void)clientinfo;
	if (sigclient == SIGUSR1)
		++count_signals;
	else if (sigclient == SIGUSR2)
	{
		ft_printf("Congrats! %d characters received!\n", count_signals);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					len;
	struct sigaction	s_clientaction;

	s_clientaction.sa_sigaction = ft_actclient;
	s_clientaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_clientaction, NULL);
	sigaction(SIGUSR2, &s_clientaction, NULL);
	if (argc == 3)
	{
		pid = ft_mini_atoi(argv[1]);
		if (pid != 0)
		{
			len = (int)ft_strlen(argv[2]);
			ft_printf("%d charachters sent!\n", len);
			ft_send_string(argv[2], pid);
		}
		else
			ft_printf("Wrong PID");
	}
	else
		ft_printf("Wrong input, please try again\n");
	while (1)
		pause();
	return (0);
}
