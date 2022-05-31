/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:16:36 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/19 17:05:58 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "Libft/libft.h"

void	ft_send_signal(int pid_server, char c)
{
	int	q;
	int	ascii;

	ascii = 0;
	q = 0;
	while (q < 8)
	{
		if ((c & (0x01 << q)) != 0)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		usleep(100);
		q++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		i = -1;
		while (argv[2][++i])
			ft_send_signal(pid_server, argv[2][i]);
		ft_send_signal(pid_server, argv[2][i]);
	}
	else
		ft_putstr_fd("Usage: ./client [pid] [string]", 1);
	return (0);
}
