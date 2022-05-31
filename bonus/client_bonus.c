/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:16:36 by zcanales          #+#    #+#             */
/*   Updated: 2022/01/18 10:14:04 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../Libft/libft.h"

void	ft_send_signal(int pid_server, char c)
{
	int	q;
	int	i;

	i = -1;
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

void	ft_send_client_pid(int pid_server)
{
	char	*pid_client;
	int		pid_client_len;
	int		i;

	i = -1;
	pid_client = ft_itoa(getpid());
	pid_client_len = ft_strlen(pid_client);
	ft_send_signal(pid_server, pid_client_len + '0');
	while (pid_client[++i])
		ft_send_signal(pid_server, pid_client[i]);
	ft_send_signal(pid_server, pid_client[i]);
	free(pid_client);
}

void	signal_handler(int signal)
{
	static int	i;

	if (!i)
		i = 0;
	i++;
	ft_putstr_fd("Received nº == ", 1);
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int					pid_server;
	int					i;
	struct sigaction	client;

	client.sa_handler = signal_handler;
	sigemptyset(&client.sa_mask);
	client.sa_flags = 0;
	sigaction(SIGUSR1, &client, NULL);
	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		ft_send_client_pid(pid_server);
		i = -1;
		while (argv[2][++i])
			ft_send_signal(pid_server, argv[2][i]);
		ft_send_signal(pid_server, argv[2][i]);
	}
	else
		ft_putstr_fd("Usage: ./client_bonus [pid] [string]", 1);
	return (0);
}
