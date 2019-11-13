/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:19:58 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/13 18:42:41 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_flag_minus(char conv, int width, int precision, va_list list)
{
	int i;
	char *p;

	i = 0;
	if (conv == 'c' || conv == 'p')
	{
		if (conv == 'c')
		{
			ft_putchar_fd(va_arg(list, int), 1);
			width--;
		}
		else
		{
			p = ft_strjoin("0x", ft_hex(va_arg(list, long long)));
			ft_putstr_fd(p, 1);
			width -= ft_strlen(p); 
		}
		while (i++ < width)
			ft_putchar_fd(' ', 1);
		free(p);
		return (i + ft_strlen(p));
	}
	if (conv == 's' || conv == 'd' || conv == 'i' || conv == 'u'
			|| conv == 'x' || conv == 'X')
	{
		i = 0;
		if (conv == 's')
		{
			p = ft_strdup(va_arg(list, char *));
			while (precision-- > 0 && *p)
			{
				ft_putchar_fd(*p, 1);
				i++;
				p++;
			}
			while (i++ < width)
				ft_putchar_fd(' ', 1);
		//	free(p);
			return (i);
		}
		else if (conv == 'd' || conv == 'i')
		{
			p = ft_itoa(va_arg(list, int));
			if (p[0] == '-')
			{
				ft_putchar_fd('-', 1);
				p = p + 1;
			}
			if (precision > (int)ft_strlen(p))
				i = precision - ft_strlen(p);
			while (i-- > 0)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(p, 1);
			while (--width > (int )ft_strlen(p))
				ft_putchar_fd(' ', 1);
		}
		else if (conv == 'x' || conv == 'X')
		{
			if (conv == 'x')
				p = ft_hex(va_arg(list, long long));
			else
				p = ft_upper(ft_hex(va_arg(list, long long)));
			if (precision > (int)ft_strlen(p))
				i = precision - ft_strlen(p);
			while (i-- > 0)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(p, 1);
			while (width-- > precision)
				ft_putchar_fd(' ', 1);
		}
	}
	return (precision);
}
