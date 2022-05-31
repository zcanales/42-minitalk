/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:07:36 by zcanales          #+#    #+#             */
/*   Updated: 2022/01/18 10:01:30 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../Libft/libft.h"
#include <stdio.h>

int	mascare(int bit, int ascii, int signal)
{
	if (!bit || bit == 8)
		ascii = 0;
	if (signal == 31)
		ascii += 0x01 << bit;
	return (ascii);
}

char	*get_client_pid(int signal)
{
	static int	bit;
	static int	ascii;
	char		*pid_client;
	static int	i;

	if (!bit || bit == 8)
		bit = 0;
	ascii = mascare(bit, ascii, signal);
	bit++;
	if (bit == 8 && !pid_client)
	{
		pid_client = (char *) malloc((int)ascii + 1);
		if (!pid_client)
			return (NULL);
		i = -1;
	}
	else if (bit == 8 && ascii && pid_client)
		pid_client[++i] = ascii;
	else if (bit == 8 && !ascii && pid_client)
	{
		pid_client[++i] = '\0';
		return (pid_client);
	}
	return (NULL);
}

int	write_message(int signal, char **pid_client)
{
	static int	bit;
	static int	ascii;

	if (!bit || bit == 8)
	{
		bit = 0;
		ascii = 0;
	}
	if (signal == 31)
		ascii += 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &ascii, 1);
		kill(ft_atoi(*pid_client), SIGUSR1);
	}
	if (bit == 8 && !ascii)
	{
		write(1, "\n", 1);
		*pid_client = 0;
		return (1);
	}
	return (0);
}

void	signal_handler(int signal)
{
	static char	*pid_client;
	static int	fre;

	if (!pid_client)
		pid_client = get_client_pid(signal);
	else
	{
		fre = write_message(signal, &pid_client);
		if (fre)
		{
			free(pid_client);
			fre = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	server;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Usage: ./server_bonus", 1);
		return (0);
	}
	ft_putstr_fd("Server PID == ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	server.sa_handler = signal_handler;
	sigemptyset(&server.sa_mask);
	server.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &server, NULL);
		sigaction(SIGUSR2, &server, NULL);
		pause();
	}
	return (0);
}
