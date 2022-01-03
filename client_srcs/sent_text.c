/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sent_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:46:04 by kkai              #+#    #+#             */
/*   Updated: 2022/01/03 17:58:03 by kkai             ###   ########.fr       */
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
		usleep(100);
		bit = (c >> i) & 1;
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
		if (argv[i] == '\0')
			break;
		i++;

	}
	// send_bit(server_pid, '\0');
}

static void	handler(int sig)
{
	(void)sig;
	g_flag = 1;
	ft_putendl_fd("Success sent message", STDOUT_FILENO);
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
