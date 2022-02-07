/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:26:22 by marlean           #+#    #+#             */
/*   Updated: 2022/01/21 12:19:55 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_bonus	bonus_null(void)
{
	struct s_bonus	t_bonus;

	t_bonus.i = 0;
	t_bonus.c = 0;
	t_bonus.nullcount = 0;
	return (t_bonus);
}

static void	ft_sighandle(int signal, siginfo_t *siginfo, void *context)
{
	static struct s_bonus	t_bonus;

	(void)context;
	if (!t_bonus.pid || t_bonus.pid != siginfo->si_pid)
	{
		t_bonus = bonus_null();
		t_bonus.pid = siginfo->si_pid;
	}
	t_bonus.c |= (signal == SIGUSR1);
	t_bonus.nullcount += (signal == SIGUSR2);
	if (++t_bonus.i == 8)
	{	
		if (t_bonus.nullcount == 8)
		{	
			kill(siginfo->si_pid, SIGUSR2);
			return ;
		}
		write(1, &t_bonus.c, 1);
		t_bonus = bonus_null();
		kill(siginfo->si_pid, SIGUSR1);
	}
	else
		t_bonus.c <<= 1;
}

int	main(void)
{
	struct sigaction	s_servaction;

	ft_printf("Server PID: %d\n", getpid());
	s_servaction.sa_sigaction = ft_sighandle;
	s_servaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_servaction, NULL);
	sigaction(SIGUSR2, &s_servaction, NULL);
	while (1)
		pause();
	return (0);
}
