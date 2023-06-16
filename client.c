/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:42:42 by isitbon           #+#    #+#             */
/*   Updated: 2023/06/15 20:38:53 by isitbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit++;
		usleep(50);
	}
}

void	send_message(pid_t server_pid, const char *message)
{
	size_t	i;

	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, 0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s [server_pid] [message]\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (0);
}
