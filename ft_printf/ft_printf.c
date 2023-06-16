/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:28:43 by isitbon           #+#    #+#             */
/*   Updated: 2023/03/07 16:22:15 by isitbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printcase(va_list vl, const char *s, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len += ft_putchar((char)(va_arg(vl, int)));
	else if (s[i] == 's')
		len += ft_putstr((va_arg(vl, char *)));
	else if (s[i] == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_putnbr_p(va_arg(vl, unsigned long long int));
	}
	else if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr_di(va_arg(vl, int));
	else if (s[i] == 'u')
		len += ft_putnbr_u(va_arg(vl, unsigned int));
	else if (s[i] == 'x')
		len += ft_putnbr_x(va_arg(vl, unsigned int));
	else if (s[i] == 'X')
		len += ft_putnbr_xx(va_arg(vl, unsigned int));
	else
		len += ft_putchar(s[i]);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	vl;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(vl, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i])
				len += ft_printcase(vl, s, i++);
		}
		else
			len += ft_putchar(s[i++]);
	}
	va_end(vl);
	return (len);
}
