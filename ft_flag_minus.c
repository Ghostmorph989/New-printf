/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:19:58 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 12:09:49 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_flag_minus(char conv, int width, int precision, va_list list)
{
	int i;
	int j;
	char *p;

	i = 0;
	j = 0;
	if (conv == 'c' || conv == 'p')
	{
		if (conv == 'c')
		{
			ft_putchar_fd(va_arg(list, int), 1);
			width--;
			j++;
		}
		else
		{
			p = ft_strjoin("0x", ft_hex(va_arg(list, long long)));
			ft_putstr_fd(p, 1);
			j = ft_strlen(p);
			width -= j; 
		}
		while (i++ < width)
			ft_putchar_fd(' ', 1);
		return (j + i);
	}
	if (conv == 's' || conv == 'd' || conv == 'i' || conv == 'u'
			|| conv == 'x' || conv == 'X')
	{
		i = 0;
		if (conv == 's')
		{
			p = ft_strdup(va_arg(list, char *));
			while (precision-- > 0 && p[j] != '\0')
				ft_putchar_fd(p[j++], 1);
			while (j++ < width)
				ft_putchar_fd(' ', 1);
			return (j - precision + width);
		}
		else if (conv == 'd' || conv == 'i')
		{
			p = ft_itoa(va_arg(list, int));
			if (p[0] == '-')
			{
				ft_putchar_fd('-', 1);
				j++;
				p = p + 1;
			}
			if (precision > (int)ft_strlen(p))
				i = precision - ft_strlen(p);
			while (i-- > 0)
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			if (width > precision)
			{
				while (width-- > precision)
				{
					j++;
					ft_putchar_fd(' ', 1);
				}
			}
			return (j + ft_strlen(p) - 1);
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
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			while (width-- > precision)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			return (j + ft_strlen(p));
		}
	}
	return (0);
}
