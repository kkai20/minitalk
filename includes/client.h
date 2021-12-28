/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:03:46 by kkai              #+#    #+#             */
/*   Updated: 2021/12/28 18:35:49 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# define EOT 0x4

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>
# include <libc.h>
# include <sysexits.h>

void	send_text(pid_t server_pid, char *argv);
void	receive_ack(void);
void	error_msg(char *msg);

extern int	global_flag;

#endif
