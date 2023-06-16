/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:17:07 by isitbon           #+#    #+#             */
/*   Updated: 2023/06/16 19:20:28 by isitbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include "ft_printf/ft_printf.h"

size_t	ft_strlen(unsigned char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

unsigned char	*ft_strjoin(unsigned char *s1, unsigned char s2)
{
	unsigned char	*str;
	size_t			i;
	size_t			i2;

	i = 0;
	i2 = 0;
	str = malloc(sizeof(unsigned char) * (ft_strlen(s1) + 1 + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	str[i++] = s2;
	str[i] = '\0';
	return (str);
}

static void	handle_signal(int sig)
{
	static unsigned char	c = 0;
	static int				bit = 0;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
