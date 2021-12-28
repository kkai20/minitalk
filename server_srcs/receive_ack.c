/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_ack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:38:50 by kkai              #+#    #+#             */
/*   Updated: 2021/12/28 13:43:47 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

static void	print_msg(char *tmp)
{
	ft_putendl_fd(tmp, 1);
}

static void	convert_bit(int bit)
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
	if(i == 8)
	{
		buff[j] = msg;
		if (j > SIZE - 1)
			error_msg("buffer overflow");
		if (buff[j] == EOT)
		{
			print_msg(buff);
			j = -1;
			ft_bzero(buff, SIZE);
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

void	receive_ack(void)
{
	struct sigaction act;


	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
