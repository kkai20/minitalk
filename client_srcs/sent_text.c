/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sent_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:46:04 by kkai              #+#    #+#             */
/*   Updated: 2021/12/29 15:27:58 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static void	send_bit(pid_t server_pid, char c)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(1000);
		bit = (c >> i) & 1;
		printf("client bit------%d\n", bit);
		if (bit == 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error_msg("kill error");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error_msg("kill error");
		}
		i++;
	}
}

void	send_text(pid_t server_pid, char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		send_bit(server_pid, argv[i]);
		i++;
	}
	send_bit(server_pid, EOT);
}

static void	handler(int sig)
{
		ft_putendl_fd("Success sent message", STDOUT_FILENO);
	if (sig == SIGUSR1)
	{
		global_flag = 1;
	}
}

void	receive_ack(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(sigaction));
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		error_msg("signal error");
}
