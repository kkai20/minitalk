/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:13:45 by kkai              #+#    #+#             */
/*   Updated: 2021/12/28 16:06:34 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	print_pid(void)
{
	ft_putstr_fd("SERVER'S PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
}

int	main(void)
{
	print_pid();
	receive_ack();
	while (1)
		;
}
