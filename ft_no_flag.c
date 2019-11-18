/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:47:23 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 18:17:09 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_manage_norm_c(t_combo *foo, va_list list)
{
	int i;

	i = 0;
	while (--(foo->width) > 0)
	{
		i++;
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd(va_arg(list, int), 1);
	return (i + 1);
}

int		ft_manage_norm_p(t_combo *foo, va_list list)
{
	int i;
	char *p;

	i = 0;
	p = ft_strjoin("0x", ft_hex(va_arg(list, long long)));
	i = ft_strlen(p);
	while (i < (foo->width))
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr_fd(p, 1);
	free(p);
	return (i);
}

int		ft_manage_norm_s(t_combo *foo, va_list list)
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
		while (len < (foo->width))
		{
			ft_putchar_fd(' ', 1);
			(foo->precision)++;
			(foo->width)--;
		}
		ft_putstr_fd(p, 1);
		return ((foo->precision) + len);
	}
	else
	{
		if ((foo->precision) > len)
			(foo->precision) = len;
		else
			len = (foo->precision);
		while (len < (foo->width)--)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		if ((foo->flag) != 1)
		{
			if (len > (foo->precision))
				ft_putstr_fd(p, 1);
			while (j < (foo->precision))
				ft_putchar_fd(p[j++], 1);
		}
		return (i + j);
	}
}

int		ft_manage_norm_di(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, int));
	len = ft_strlen(p);
		if ((foo->precision) == 0)
		{
			while ((foo->width)-- > len)
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			if (p[0] == '-' && (foo->width) != 0)
			{
				ft_putchar_fd('-', 1);
				p = p + 1;
			}
			ft_putstr_fd(p, 1);
			return (i + len);
		}
		else
		{
			if (p[0] == '-')
				(foo->width)--;
			while (--(foo->width) >= (foo->precision))
			{
				i++;
				ft_putchar_fd(' ', 1);
			}
			if (p[0] == '-' && (foo->width) != 0)
			{
				ft_putchar_fd('-', 1);
				p = p + 1;
			}
			while ((foo->precision) > len)
			{
				ft_putchar_fd('0', 1);
				i++;
				(foo->precision)--;
			}
			if (ft_atoi(p) != 0 && (foo->precision) != 0)
				ft_putstr_fd(p, 1);
			else if ((foo->precision) > 0)
			{
				ft_putchar_fd('0', 1);
			}
			return (i + len);
		}
}

int		ft_manage_norm_x(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_hex(va_arg(list, long long));
	len = ft_strlen(p);
	if ((foo->width) > (foo->precision))
		{
			while ((foo->width)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
		else
		{
			i = (foo->precision);
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			while (--(foo->width) > i)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
}

int		ft_manage_norm_X(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_upper(ft_hex(va_arg(list, long long)));
	len = ft_strlen(p);
	if ((foo->width) > (foo->precision))
		{
			while ((foo->width)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
		else
		{
			i = (foo->precision);
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			while (--(foo->width) > i)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
}
int		ft_manage_norm_u(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, unsigned int));
	len = ft_strlen(p);
	if ((foo->precision) < 0)
			(foo->precision) = 0;
		if ((foo->width) > (foo->precision))
		{
			while ((foo->width)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j  + ft_strlen(p));
		}
		else
		{
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
}

int		ft_no_flag(char conv, t_combo *foo, va_list list)
{
	if (conv == 'c')
		return (ft_manage_norm_c(foo, list));
	else if (conv == 'p')
		return (ft_manage_norm_p(foo, list));
	else if (conv == 's')
		return (ft_manage_norm_s(foo, list));
	else if (conv == 'd' || conv == 'i')
		return (ft_manage_norm_di(foo, list));
	else if (conv == 'x')
		return (ft_manage_norm_x(foo, list));
	else if (conv == 'X')
		return (ft_manage_norm_X(foo, list));
	else if (conv == 'u')
		return (ft_manage_norm_u(foo, list));
	return (0);
}