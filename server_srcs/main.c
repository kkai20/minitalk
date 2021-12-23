/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:13:45 by kkai              #+#    #+#             */
/*   Updated: 2021/12/23 14:32:28 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	handler(int sig)
{
	printf("テスト\n, %d\n", sig);
}
// シグナルを受け取る
//シグナルごとに処理を変える
int main()
{
	struct sigaction act;

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	// sigaddset(&sa_)
	// act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	// sigaction(SIGUSR2, &act, NULL);

	while (1)
		;
	return (0);
}
