/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:07:36 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/19 17:06:05 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "Libft/libft.h"

void	signal_handler(int signal)
{
	static int	bit;
	static int	ascii;

	if (!ascii || bit == 8)
		ascii = 0;
	if (!bit || bit == 8)
		bit = 0;
	if (signal == 31)
		ascii += 0x01 << bit;
	bit++;
	if (bit == 8)
		write(1, &ascii, 1);
	if (bit == 8 && !ascii)
		write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Usage: ./server", 1);
		return (0);
	}
	ft_putstr_fd("Server PID == ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	while (1)
	{	
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
