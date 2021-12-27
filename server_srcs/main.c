/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:13:45 by kkai              #+#    #+#             */
/*   Updated: 2021/12/28 01:03:54 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	print_msg(char *tmp)
{
	ft_putendl_fd(tmp, 1);
}

void	convert_bit(int bit)
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
			erroor_msg("buffer overflow");
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

void	handler(int sig, siginfo_t *info, void *q)
{
	(void)q;
	if (sig == SIGUSR1)
		convert_bit(1);
	if (sig == SIGUSR2)
		convert_bit(0);
}
void	receive_signal(void)
{
	struct sigaction act;


	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

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
