/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:52:22 by zcanales          #+#    #+#             */
/*   Updated: 2021/10/13 12:46:59 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int				negative;
	int				i;
	unsigned int	sum;

	sum = 0;
	i = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (ft_isdigit((int)str[i]))
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	if (sum > 2147483647 && negative == 1)
		return (-1);
	if (sum > 2147483648 && negative == -1)
		return (0);
	return (sum * negative);
}
