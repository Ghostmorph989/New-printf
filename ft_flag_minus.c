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
	if ((foo->cc) == 1)
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd(va_arg(list, int), 1);
	while (--(foo->width) > 0)
	{
		i++;
		ft_putchar_fd(' ', 1);
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
	if (p != NULL)
		len = ft_strlen(p); 
	else if (p == NULL)
	{
		p = ft_strdup("(null)");
		len = ft_strlen(p);
	}
	else
		len = -1;
	if ((foo->precision) == 0)
	{
		
		if ((foo->width) == 0)
			return (0);
		if ((foo->flag) == 1)
			j = 0;
		else
			j = len;
		if ((foo->flag) != 1)
		{
			i += len;
			ft_putstr_fd(p, 1);
		}
		while (j < (foo->width))
		{
			ft_putchar_fd(' ', 1);
			i++;
			(foo->width)--;
		}
		return (i);
	}
	else if ((foo->precision > 0))
	{
		if ((foo->precision) > len && (foo->precision) != -1)
			(foo->precision) = len;
		if ((foo->precision) < len && (foo->precision) != -1)
			len = (foo->precision);
		if (len > (foo->precision) && (foo->flag) == 0)
			ft_putstr_fd(p, 1);
		while (j < (foo->precision))
			ft_putchar_fd(p[j++], 1);
		while (len < (foo->width)--)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		return (i + j);
	}
	else
	{
		ft_putstr_fd(p, 1);
		while ((foo->width)-- > len)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		return (len + i);
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
		if ((foo->precision) == 0)
		{
			j = (foo->width);
			if (p[0] == '-')
			{
				ft_putchar_fd('-', 1);
				p = p + 1;
			}
			if (((foo->flag) == 0) || ((ft_atoi(p) != 0) || (foo->precision != 0)))
				ft_putstr_fd(p, 1);
			else if (((foo->flag) == 1 || (ft_atoi(p) != 0)) && j != 0)
				i--;
			if ((foo->width) != 0 && (foo->flag) == 1 && ft_atoi(p) == 0)
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			while (j-- > len)
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			return (i + len);
		}
		else
		{
			j = (foo->width);
			if ((foo->precision) < len)
				(foo->precision)++;
			if (p[0] == '-')
			{
				ft_putchar_fd('-', 1);
				p += 1;
				if ((foo->precision) < (foo->width))
				{
					(foo->precision)++;
					i--;
				}
				else
					len--;
				i++;
			}
			while ((foo->precision)-- > len)
			{
				ft_putchar_fd('0', 1);
				i++;
				j--;
			}
			if ((foo->flag) == 0)
				ft_putstr_fd(p, 1);
			else if ((foo->precision) > 0)
				ft_putchar_fd('0', 1);
			while (--j > (foo->precision))
			{
				i++;
				ft_putchar_fd(' ', 1);
			}
			return (i + len);
		}
}
int		ft_manage_minus_x(t_combo *foo, va_list list)
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
			ft_putstr_fd(p, 1);
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			return (j + ft_strlen(p));
		}
		else
		{
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			while (--(foo->width) > i)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			return (j + ft_strlen(p));
		}
}

int		ft_manage_minus_X(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_upper(ft_hex(va_arg(list, long)));
	len = ft_strlen(p);
	if ((foo->width) < (foo->precision))
		{
			while ((foo->width)-- > len)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			while ((foo->precision)-- > len)
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			return (j + ft_strlen(p));
		}
		else
		{
			while ((foo->width)-- > (foo->precision))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			return (j + ft_strlen(p) - 1);
		}
}

int		ft_manage_minus_u(t_combo *foo, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, unsigned int));
	len = ft_strlen(p);
	if ((foo->width) > (foo->precision))
		{
			j = (foo->precision) + len;
			ft_putstr_fd(p, 1);
			while ((foo->precision)-- > (int)ft_strlen(p))
			{
				i++;
				ft_putchar_fd('0', 1);
			}
			while ((foo->width)-- > j)
			{
				i++;
				ft_putchar_fd(' ', 1);
			}
			return (i + ft_strlen(p));
		}
		else
		{
			ft_putstr_fd(p, 1);
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
			return (j + ft_strlen(p));
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
	else if (conv == 'x')
		return (ft_manage_minus_x(foo, list));
	else if (conv == 'X')
		return (ft_manage_minus_X(foo, list));
	else if (conv == 'u')
		return (ft_manage_minus_u(foo, list));
	return (0);
}