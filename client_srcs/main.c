/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:10 by kkai              #+#    #+#             */
/*   Updated: 2021/12/28 19:01:14 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int global_flag;

void error_msg(char *msg)
{
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

static int	check_string(char *msg)
{
	if (*msg == '\0')
		return (0);
	return (1);
}

static int	check_pid(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	if (0 < ft_atoi(num) && ft_atoi(num) < INT_MAX)
		return (1);
	return (0);
}

static void	check_argv(int argc, char **argv)
{
	if (argc != 3)
		error_msg("Please set process id and messages");
	if (check_pid(argv[1]) == 0)
		error_msg("process id is invalid");
	if (check_string(argv[2]) == 0)
		error_msg("messages is invalid");
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	global_flag = 0;
	check_argv(argc, argv);
	server_pid = (pid_t)ft_atoi(argv[1]);
	receive_ack();
	send_text(server_pid, argv[2]);
	if (!sleep(5))
		error_msg("time out");
	// if (global_flag == 0)
		// error_msg("session error");
	return (0);
}
