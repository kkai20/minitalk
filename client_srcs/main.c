/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:10 by kkai              #+#    #+#             */
/*   Updated: 2021/12/19 23:43:00 by kkai             ###   ########.fr       */
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

int	main(int argc, char **argv)
{

	// クライアントがプロセスIDを取得
	pid_t	server_pid;
	// (void)argc;

	//コマンドライン引数の数がおかしかったらエラーを吐く
	check_argv(argc, argv);

	// プロセスidを数値に変換する
	server_pid = ft_atoi(argv[1]);
	// シグナルを送る

	kill((server_pid), SIGSEGV);
	return 0;

	= getpid();

	// 受け取った文字列をビットに変換させる
	send
	// １ビットずつサーバーにメッセージを送信する

	// サーバ側からのACKを受け付ける

	// データを最後まで送ったら、文字列の最後にEOTをつける

	// サーバー側からのACKを受け付ける

}
