/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:10 by kkai              #+#    #+#             */
/*   Updated: 2021/12/27 23:37:29 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	check_pid(char *num)
{
	int i;

	i = 0;
	while(num[i])
	{
		if (ft_isdigit(num[i]) == FALSE)
			return (FALSE);
		i++;
	}
	if (0 < ft_atoi(num) && ft_atoi(num) < INT_MAX)
		return (TRUE);
	return (FALSE);
}

int	check_string(char *msg)
{
	if (*msg == '\0')
		return (FALSE);
	return (TRUE);
}

void	check_argv(int argc, char **argv)
{
	if (argc != 3)
		error_msg("Please set process id and messages");
	if (check_pid(argv[1]) == FALSE)
		error_msg("process id is invalid");
	if (check_string(argv[2]) == FALSE)
		error_msg("messages is invalid");
}

void	send_bit(pid_t server_pid, char c)
{
	int bit;
	int i;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
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

void	handler(int sig)
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

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	check_argv(argc, argv);
	server_pid = ft_atoi(argv[1]);
	receive_ack();
	send_text(server_pid, argv[2]);
	return (0);
}
