/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:10 by kkai              #+#    #+#             */
/*   Updated: 2021/12/23 14:48:28 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

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
	{
		ft_putendl_fd("Please set process id and messages", 1);
		exit(EXIT_FAILURE);
	}
	if (check_pid(argv[1]) == FALSE)
	{
		ft_putendl_fd("process id is invalid", 1);
		exit(EXIT_FAILURE);
	}
	if (check_string(argv[2]) == FALSE)
	{
		ft_putendl_fd("messages is invalid", 1);
		exit(EXIT_FAILURE);
	}
}

	// 受け取った文字列をビットに変換させる
void	send_bit(pid_t server_pid, char c)
{
	int bit;
	int i;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		}
}

// メッセージを１文字ずつビット変換関数に渡す
void	send_text(pid_t server_pid, char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		send_bit(server_pid, argv[i]);
		// printf("%d\n, %c\n", server_pid, argv[i]);
		i++;
	}
	send_bit(server_pid, EOT);
}

int	main(int argc, char **argv)
{

	pid_t	server_pid;
	// (void)argc;

	//コマンドライン引数の数がおかしかったらエラーを吐く
	check_argv(argc, argv);

	server_pid = ft_atoi(argv[1]);

	// getpid();
	kill(server_pid, SIGUSR1);
	// send_text(server_pid, argv[2]);
	// １ビットずつサーバーにメッセージを送信する

	// サーバ側からのACKを受け付ける

	// データを最後まで送ったら、文字列の最後にEOTをつける

	// サーバー側からのACKを受け付ける
	return (0);
}
