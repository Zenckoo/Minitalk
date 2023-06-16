/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:33:47 by isitbon           #+#    #+#             */
/*   Updated: 2023/03/07 16:26:25 by isitbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = len_u(n);
	if (n >= 10)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (len);
}
