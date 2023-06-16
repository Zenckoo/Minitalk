/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isitbon <isitbon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:22:49 by isitbon           #+#    #+#             */
/*   Updated: 2023/03/07 16:25:28 by isitbon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
char	ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_p(unsigned long long int n);
int		ft_putnbr_di(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_x(unsigned int n);
int		ft_putnbr_xx(unsigned int n);

#endif