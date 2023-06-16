/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:31:51 by isitbon           #+#    #+#             */
/*   Updated: 2023/03/07 16:26:16 by isitbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_p(unsigned long long int n)
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

int	ft_putnbr_p(unsigned long long int n)
{
	int	len;

	len = len_p(n);
	if (n >= 16)
	{
		ft_putnbr_p(n / 16);
		ft_putnbr_p(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar((n - 10) + 'a');
	}
	return (len);
}
