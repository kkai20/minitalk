/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:10 by kkai              #+#    #+#             */
/*   Updated: 2021/12/19 17:25:09 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"


void	check_argv(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putendl_fd("Please set process id and messages", 1);
		exit(0);
	}
	if (argv[1] == NULL)
	{
		ft_putendl_fd("process id is invalid", 1);
		exit(0);
	}
	if (argv[2] == NULL)
	{
		ft_putendl_fd("messages is invalid", 1);
		exit(0);
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

	// 受け取った文字列をビットに変換させる

	// １ビットずつサーバーにメッセージを送信する

	// サーバ側からのACKを受け付ける

	// データを最後まで送ったら、文字列の最後にEOTをつける

	// サーバー側からのACKを受け付ける

}
