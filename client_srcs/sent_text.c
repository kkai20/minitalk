/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sent_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:46:04 by kkai              #+#    #+#             */
/*   Updated: 2021/12/28 15:50:42 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"


static void	send_bit(pid_t server_pid, char c)
{
	int bit;
	int i;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		bit = (c >> i) & 1;
		if (bit == 1)
			if(kill(server_pid, SIGUSR1) == -1)
				error_msg("kill eroor");
		else
			if(kill(server_pid, SIGUSR2) == -1)
				error_msg("kill eroor");
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
	if (sig == SIGUSR1)
		ft_putendl_fd("Success sent message", STDOUT_FILENO);
}

void	receive_ack(void)
{
	struct sigaction 	act;

	ft_bzero(&act, sizeof(sigaction));
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		error_msg("signal error");
}
