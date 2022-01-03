/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_ack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:38:50 by kkai              #+#    #+#             */
/*   Updated: 2022/01/03 18:06:28 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

static void	print_msg(char *buff, int j, pid_t client_pid)
{
	printf("j ----%d", j);
	if (buff[j] == '\0')
	{
		write(STDOUT_FILENO, buff, j - 1);
		kill(client_pid, SIGUSR1);
	}
	else
	{
		write(STDOUT_FILENO, buff, j);
	}
}

static void	convert_bit(int bit, pid_t client_pid)
{
	static char	msg;
	static char	buff[SIZE];
	static int	i;
	static int	j;

	if (i < 8)
	{
		msg |= (bit << i);
		i++;
	}
	if (i == 8)
	{
		buff[j] = msg;
		j++;
		if (msg == '\0' || j >= SIZE)
		{
			print_msg(buff, j, client_pid);
			j = 0;
		}
		j++;
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
