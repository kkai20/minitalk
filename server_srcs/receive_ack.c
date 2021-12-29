/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_ack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:38:50 by kkai              #+#    #+#             */
/*   Updated: 2021/12/29 17:04:10 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

static void	print_msg(char *buff, int j, pid_t client_pid)
{
	if (buff[j] == '\0')
		ft_putstr_fd(buff, STDOUT_FILENO);
	if (buff[j] == EOT)
	{
		buff[j] = '\0';
		ft_putendl_fd(buff, STDOUT_FILENO);
		kill(client_pid, SIGUSR1);
	}
}

static void	convert_bit(int bit, pid_t client_pid)
{
	static char	msg;
	static char	buff[SIZE];
	static int	i;
	static int	j;

	printf("bit--------%d\n", bit);
	if (i < 8)
	{
		msg |= (bit << i);
		i++;
	}
	if (i == 8)
	{
		printf("EOT-------%c\n", msg);
		buff[j] = msg;
		if (buff[j] == EOT)
		{
			print_msg(buff, j, client_pid);
			j = -1;
		}
		if (j == SIZE - 2 )
		{
			buff[j + 1] = '\0';
			print_msg(buff, j, client_pid);
			j = -1;
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
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
