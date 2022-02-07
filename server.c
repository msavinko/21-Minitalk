/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:40:33 by marlean           #+#    #+#             */
/*   Updated: 2022/01/27 14:07:43 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sighandle(int signal, siginfo_t *siginfo, void *context)
{
	static int	index = 0;
	static char	c = 0;
	static int	pid = 0;

	(void)context;
	if (!pid || pid != siginfo->si_pid)
	{
		index = 0;
		c = 0;
		pid = siginfo->si_pid;
	}
	c = c | (signal == SIGUSR1);
	if (++index == 8)
	{	
		index = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	s_sa;

	ft_printf("Server PID: %d\n", getpid());
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = ft_sighandle;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	while (1)
		pause();
	return (0);
}
