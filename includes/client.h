/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:03:46 by kkai              #+#    #+#             */
/*   Updated: 2022/01/03 18:58:17 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>
# include <sysexits.h>
# include <stdbool.h>

void	send_text(pid_t server_pid, char *argv);
void	receive_ack(void);
void	error_msg(char *msg);

extern int	g_flag;

#endif
