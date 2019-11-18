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

int		ft_manage_zero_c(t_combo *foo, va_list list)
{
	int i;

	i = 0;
	while (--(foo->width) > 0)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putchar_fd(va_arg(list, int), 1);
	return (i + 1);
}

int		ft_manage_zero_p(t_combo *foo, va_list list)
{
	int i;
	char *p;

	p = ft_strjoin("0x", ft_hex(va_arg(list, long long)));
	i = ft_strlen(p);
	while (i < (foo->width))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putstr_fd(p, 1);
	return (i);
}


int		ft_manage_zero_di(t_combo *foo, va_list list)
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
	if ((foo->precision) == 0)
	{
		while (len < (foo->width))
		{
			ft_putchar_fd('0', 1);
			i++;
			(foo->width)--;
		}
	}
	else
	{
		while (len < (foo->precision))
		{
			ft_putchar_fd('0', 1);
			i++;
			(foo->precision)--;
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

int		ft_manage_zero_x(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_hex(va_arg(list, long long));
	len = ft_strlen(p);
	while (len < (foo->width))
	{
		ft_putchar_fd('0', 1);
		i++;
		(foo->width)--;
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

int		ft_manage_zero_X(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_upper(ft_hex(va_arg(list, long long)));
	len = ft_strlen(p);
		while (len < (foo->width))
	{
		ft_putchar_fd('0', 1);
		i++;
		(foo->width)--;
	}
	if (ft_atoi(p) != 0)
			ft_putstr_fd(p, 1);
	else if (ft_atoi(p) == 0 && (foo->precision) == 0)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return (i + len);
}
int		ft_manage_zero_u(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, unsigned int));
	len = ft_strlen(p);
	while (len < (foo->width))
	{
		ft_putchar_fd('0', 1);
		i++;
		(foo->width)--;
	}
	if (ft_atoi(p) != 0)
		ft_putstr_fd(p, 1);
	else if (ft_atoi(p) == 0 && (foo->precision) == 0)
	{	
		ft_putchar_fd(' ', 1);
	}
	return (i + len);
}

int		ft_flag_zero(char conv, t_combo *foo, va_list list)
{
	if (conv == 'c')
	{
		if ((foo->precision) == 0)
			return (ft_manage_zero_c(foo, list));
		return (ft_manage_norm_c(foo, list));
	}
	else if (conv == 'p')
	{
		if ((foo->precision) == 0)
			return (ft_manage_zero_p(foo, list));
		return (ft_manage_norm_p(foo, list));
	}
	else if (conv == 'd' || conv == 'i')
	{
		if ((foo->precision) == 0)
			return (ft_manage_zero_di(foo, list));
		return (ft_manage_norm_di(foo, list));
	}
	else if (conv == 'x')
	{
		if ((foo->precision) == 0)
			return (ft_manage_zero_x(foo, list));
		return (ft_manage_norm_x(foo, list));
	}
	else if (conv == 'X')
	{
		if ((foo->precision) == 0)
			return (ft_manage_zero_X(foo, list));
		return (ft_manage_norm_X(foo, list));
	}
	else if (conv == 'u')
	{
		if ((foo->precision) == 0)
			return (ft_manage_zero_u(foo, list));
		return (ft_manage_norm_u(foo, list));
	}

	return (0);
}