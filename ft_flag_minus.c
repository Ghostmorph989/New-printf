/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:19:58 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 17:41:07 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_manage_minus_c(t_combo *foo, va_list list)
{
	int i;

	i = 0;
	ft_putchar_fd(va_arg(list, int), 1);
	while (--(foo->width) > 0)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i + 1);
}

int		ft_manage_minus_p(t_combo *foo, va_list list)
{
	int i;
	int len;
	char *p;

	i = 0;
	p = ft_strjoin("0x", ft_hex(va_arg(list, long long)));
	len = ft_strlen(p);
	ft_putstr_fd(p, 1);
	while ((foo->width) > len)
	{
		ft_putchar_fd(' ', 1);
		(foo->width)--;
		i++;
	}
	free(p);
	return (i + len);
}

int		ft_manage_minus_s(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = va_arg(list, char *);
	if (p == NULL)
		p = ft_strdup("(null)");
	len = ft_strlen(p); 
	if ((foo->precision) == 0)
	{
		if ((foo->width) == 0)
			return (0);
			ft_putstr_fd(p, 1);
		while (len < (foo->width))
		{
			ft_putchar_fd(' ', 1);
			(foo->precision)++;
			(foo->width)--;
		}
		return ((foo->precision) + len);
	}
	else
	{
		if ((foo->precision) == -1)
			(foo->width)--;
		if ((foo->precision) > len)
			(foo->precision) = len;
		else
			len = (foo->precision);
		while (j < (foo->precision))
			ft_putchar_fd(p[j++], 1);
		while (len < (foo->width)--)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		return (i + j);
	}
}

int		ft_manage_minus_di(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, int));
	len = ft_strlen(p);
	if ((foo->precision) == 0 || (foo->precision) == -2)
	{
		if (p[0] == '-' && (foo->width) != 0)
		{
			ft_putchar_fd('-', 1);
			p = p + 1;
			i++;
			len++;
		}
		if ((foo->precision) != -2)
			ft_putstr_fd(p, 1);
		else
			ft_putchar_fd(' ', 1);
		while ((foo->width)-- > len)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		return (i + ft_strlen(p));
	}
	else
	{
		if (p[0] == '-' && (foo->width) != 0)
		{
			ft_putchar_fd('-', 1);
			p = p + 1;
			i++;
		}
		while ((foo->precision)-- > (int )ft_strlen(p))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		ft_putstr_fd(p, 1);
		if ((foo->precision) > 0)
		{
		while (--(foo->width) > (foo->precision))
		{
			i++;
			ft_putchar_fd(' ', 1);
		}
		}
		return (i + ft_strlen(p));
	}
}
int		ft_flag_minus(char conv, t_combo *foo, va_list list)
{
	if (conv == 'c')
		return (ft_manage_minus_c(foo, list));
	else if (conv == 'p')
		return (ft_manage_minus_p(foo, list));
	else if (conv == 's')
		return (ft_manage_minus_s(foo, list));
	else if (conv == 'd' || conv == 'i')
		return (ft_manage_minus_di(foo, list));
	// else if (conv == 'x')
	// 	return (ft_manage_minus_x(foo, list));
	// else if (conv === 'X')
	// 	return (ft_manage_minus_X(foo, list));
	// else if (conv == 'u')
	// 	return (ft_manage_minus_u(foo, list));
	return (0);
}