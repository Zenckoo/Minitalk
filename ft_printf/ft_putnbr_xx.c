/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:25:39 by isitbon           #+#    #+#             */
/*   Updated: 2023/03/07 16:26:40 by isitbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_xx(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_xx(unsigned int n)
{
	int	len;

	len = len_xx(n);
	if (n >= 16)
	{
		ft_putnbr_xx(n / 16);
		ft_putnbr_xx(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar((n - 10) + 'A');
	}
	return (len);
}
