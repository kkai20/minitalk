/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_ack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:38:50 by kkai              #+#    #+#             */
/*   Updated: 2022/01/03 19:10:30 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

static void	convert_bit(int bit, pid_t client_pid)
{
	static char	msg;
	static char	buff[SIZE];
	static int	i;
	static int	bytes;

	if (i < 8)
	{
		msg |= (bit << i);
		i++;
	}
	if (i == 8)
	{
		buff[bytes] = msg;
		bytes++;
		if (msg == '\0')
		{
			write(STDOUT_FILENO, buff, bytes - 1);
			bytes = 0;
			kill(client_pid, SIGUSR1);
		}
		else if (bytes >= SIZE)
		{
			write(STDOUT_FILENO, buff, SIZE);
			bytes = 0;
		}
		i = 0;
		msg = 0;
	}
}

static void	handler(int sig, siginfo_t *info, void *q)
{
	(void)q;
	if (sig == SIGUSR1)
		convert_bit(1, info->si_pid);
	if (sig == SIGUSR2)
		convert_bit(0, info->si_pid);
}

void	set_sigaction(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1 \
	|| sigaction(SIGUSR2, &act, NULL) == -1)
		error_msg("sigaction error!");
}
