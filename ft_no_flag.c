/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:47:23 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/13 23:25:14 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		ft_no_flag(char conv, int width, int precision, va_list list)
{
	char *p;
	int i;

	i = 0;
	if (conv == 'c')
	{
		p = ft_strdup(va_arg(list, int));
		while (width-- > 1)
		{
			i++;
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd(p, 1);

	}
	if (conv == 's')
	{
		p = ft_strdup(va_arg(list, char *));
		while (width-- > (int)ft_strlen(p))
			ft_putchar_fd(' ', 1);
		while (precision-- > 0 && p[i])
			ft_putchar_fd(p[i++], 1);
		return (i);
	}
	if (conv == 'd' || conv == 'i')
	{
		p = ft_itoa(va_arg(list, int));
		if (precision < 0)
			precision = 0;
		if (precision == 0)
		{
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				p[0] = '0';
				width--;
			}
			while (width-- > (int )ft_strlen(p))
				ft_putchar_fd('0', 1);
			ft_putstr_fd(p, 1);
			return (0);
		}
		else
		{
			while (--width > precision && precision != 0)
				ft_putchar_fd(' ', 1);
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				p[0] = '0';
			}
			while (precision-- > (int )ft_strlen(p))
				ft_putchar_fd('0', 1);
			ft_putstr_fd(p, 1);
		}
	}
	if (conv == 'x')
	{
		p = ft_hex(va_arg(list, long long));
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
				ft_putchar_fd(' ', 1);
			while (precision-- > (int)ft_strlen(p))
				ft_putchar_fd('0', 1);
			ft_putstr_fd(p, 1);
		}
		else
		{
			i = precision;
			while (precision-- > (int)ft_strlen(p))
				ft_putchar_fd('0', 1);
			while (--width > i)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(p, 1);
		}
	}
	if (conv == 'X')
	{
		p = ft_upper(ft_hex(va_arg(list, long long)));
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
				ft_putchar_fd(' ', 1);
			while (precision-- > (int)ft_strlen(p))
				ft_putchar_fd('0', 1);
			ft_putstr_fd(p, 1);
		}
		else
		{
			i = precision;
			while (precision-- > (int)ft_strlen(p))
				ft_putchar_fd('0', 1);
			while (--width > i)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(p, 1);
		}
	}
	if (conv == 'u')
	{
		p = ft_itoa(va_arg(list, unsigned int));
		if (precision < 0)
			precision = 0;
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(p, 1);
		}
		else
		{
			while (precision-- > (int)ft_strlen(p))
				ft_putchar_fd('0', 1);
			ft_putstr_fd(p, 1);
		}
	}
	return (0);
}
