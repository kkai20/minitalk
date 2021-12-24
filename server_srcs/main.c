/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:13:45 by kkai              #+#    #+#             */
/*   Updated: 2021/12/24 14:26:38 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	print_msg(char *tmp)
{
	ft_putendl_fd(tmp, 1);
	// kill(client_pid, SIGUSR1);
}

void	convert_bit(int bit)
{
	static char	msg;
	static char	tmp[1000];
	static int	i;
	static int	j;

	if (i < 8)
	{
		msg += (bit << i);
		i++;
	}
	if(i == 8)
	{
		tmp[j] = msg;
		if (tmp[j] == EOT)
		{
			print_msg(tmp);
		}
		j++;
		i = 0;
		msg = 0;
	}
}

void	handler(int sig)
// siginfo_t *info, void *q)
{
	if (sig == SIGUSR1)
		convert_bit(1);
	// printf("ユーザー１\n, %d\n", sig);
	if (sig == SIGUSR2)
		convert_bit(0);
	// printf("ユーザー２\n, %d\n", sig);
}
void	receive_signal(void)
{
	struct sigaction act;


	ft_bzero(&act, sizeof(struct sigaction));
	// act.sa_sigaction = handler;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	// sigaddset(&sa_)
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
// シグナルを受け取る
//シグナルごとに処理を変える


void	print_pid(void)
{
	ft_putstr_fd("SERVER'S PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
}

int main()
{
	print_pid();
	receive_signal();

	while (1)
		;
}
