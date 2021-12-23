/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:13:45 by kkai              #+#    #+#             */
/*   Updated: 2021/12/23 15:45:57 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	handler(int sig)
{
	if (sig == SIGUSR1)
		printf("ユーザー１\n, %d\n", sig);
	if (sig == SIGUSR2)
		printf("ユーザー２\n, %d\n", sig);
}
void	receive_signal(void)
{
	struct sigaction act;

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	// sigaddset(&sa_)
	// act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
// シグナルを受け取る
//シグナルごとに処理を変える
int main()
{

	receive_signal();

	while (1)
		;
}
