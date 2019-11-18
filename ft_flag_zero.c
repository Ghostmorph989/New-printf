/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:46:45 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 18:03:01 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_manage_zero_c(int width, va_list list)
{
	int i;

	i = 0;
	while (--width > 0)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putchar_fd(va_arg(list, int), 1);
	return (i + 1);
}

int		ft_manage_zero_p(int width, va_list list)
{
	int i;
	char *p;

	p = ft_strjoin("0x", ft_hex(va_arg(list, long long)));
	i = ft_strlen(p);
	while (i < width)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putstr_fd(p, 1);
	return (i);
}


int		ft_manage_zero_di(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;
	int flag;

	flag = 0;
	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, int));
	len = ft_strlen(p);
	if (p[0] == '-')
	{
		ft_putchar_fd('-', 1);
		p = p + 1;
		i++;
		flag = -1;
	}
	if (precision == 0)
	{
		while (len < width)
		{
			ft_putchar_fd('0', 1);
			i++;
			width--;
		}
	}
	else
	{
		while (len < precision)
		{
			ft_putchar_fd('0', 1);
			i++;
			precision--;
		}
	}
	if (ft_atoi(p) != 0)
		ft_putstr_fd(p, 1);
	else
		ft_putchar_fd('0', 1);
	if (flag < 0)
		return (i + len - 1);
	else
	return (i + len);
}

int		ft_manage_zero_x(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_hex(va_arg(list, long long));
	len = ft_strlen(p);
	while (len < width)
	{
		ft_putchar_fd('0', 1);
		i++;
		width--;
	}
	if (ft_atoi(p) != 0)
		ft_putstr_fd(p, 1);
	else
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return (i + len);
}

int		ft_manage_zero_X(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_upper(ft_hex(va_arg(list, long long)));
	len = ft_strlen(p);
		while (len < width)
	{
		ft_putchar_fd('0', 1);
		i++;
		width--;
	}
	if (ft_atoi(p) != 0)
			ft_putstr_fd(p, 1);
	else if (ft_atoi(p) == 0 && precision == 0)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return (i + len);
}
int		ft_manage_zero_u(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, unsigned int));
	len = ft_strlen(p);
	while (len < width)
	{
		ft_putchar_fd('0', 1);
		i++;
		width--;
	}
	if (ft_atoi(p) != 0)
		ft_putstr_fd(p, 1);
	else if (ft_atoi(p) == 0 && precision == 0)
	{	
		ft_putchar_fd(' ', 1);
	}
	return (i + len);
}

int		ft_flag_zero(char conv, int width, int precision, va_list list)
{
	if (conv == 'c')
	{
		if (precision == 0)
			return (ft_manage_zero_c(width, list));
		return (ft_manage_norm_c(width, list));
	}
	else if (conv == 'p')
	{
		if (precision == 0)
			return (ft_manage_zero_p(width, list));
		return (ft_manage_norm_p(width, list));
	}
	else if (conv == 'd' || conv == 'i')
	{
		if (precision == 0)
			return (ft_manage_zero_di(width, precision, list));
		return (ft_manage_norm_di(width, precision, list));
	}
	else if (conv == 'x')
	{
		if (precision == 0)
			return (ft_manage_zero_x(width, precision, list));
		return (ft_manage_norm_x(width, precision, list));
	}
	else if (conv == 'X')
	{
		if (precision == 0)
			return (ft_manage_zero_X(width, precision, list));
		return (ft_manage_norm_X(width, precision, list));
	}
	else if (conv == 'u')
	{
		if (precision == 0)
			return (ft_manage_zero_u(width, precision, list));
		return (ft_manage_norm_u(width, precision, list));
	}

	return (0);
}