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

int		ft_manage_norm_c(int width, va_list list)
{
	int i;

	i = 0;
	while (--width > 0)
	{
		i++;
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd(va_arg(list, int), 1);
	return (i + 1);
}

int		ft_manage_norm_p(int width, va_list list)
{
	int i;
	char *p;

	i = 0;
	p = ft_strjoin("0x", ft_hex(va_arg(list, long long)));
	i = ft_strlen(p);
	while (i < width)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr_fd(p, 1);
	free(p);
	return (i);
}

int		ft_manage_norm_s(int width, int precision, va_list list)
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
	if (precision == 0)
	{
		if (width == 0)
			return (0);
		while (len < width)
		{
			ft_putchar_fd(' ', 1);
			precision++;
			width--;
		}
		ft_putstr_fd(p, 1);
		return (precision + len);
	}
	else
	{
		if (precision > len)
			precision = len;
		else
			len = precision;
		while (len < width--)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		while (j < precision)
			ft_putchar_fd(p[j++], 1);
		return (i + j);
	}
}

int		ft_manage_norm_di(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, int));
	len = ft_strlen(p);
		if (precision == 0)
		{
			while (width-- > (int )ft_strlen(p))
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				p = p + 1;
				i++;
			}
			ft_putstr_fd(p, 1);
			return (i + ft_strlen(p));
		}
		else
		{
			while (--width > precision)
			{
				i++;
				ft_putchar_fd(' ', 1);
			}
			if (p[0] == '-' && width != 0)
			{
				ft_putchar_fd('-', 1);
				p[0] = '0';
				i++;
			}
			while (precision-- > (int )ft_strlen(p))
			{
				ft_putchar_fd('0', 1);
				i++;
			}
			if (ft_atoi(p) != 0)
			{
				ft_putstr_fd(p, 1);
				return (i + ft_strlen(p));
			}
			return (i + ft_strlen(p) - 1);
		}
}

int		ft_manage_norm_x(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_hex(va_arg(list, long long));
	len = ft_strlen(p);
	if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
		else
		{
			i = precision;
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			while (--width > i)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
}

int		ft_manage_norm_X(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_upper(ft_hex(va_arg(list, long long)));
	len = ft_strlen(p);
	if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
		else
		{
			i = precision;
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			while (--width > i)
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
}
int		ft_manage_norm_u(int width, int precision, va_list list)
{
	char *p;
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	p = ft_itoa(va_arg(list, unsigned int));
	len = ft_strlen(p);
	if (precision < 0)
			precision = 0;
		if (width > precision)
		{
			while (width-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd(p, 1);
			return (j  + ft_strlen(p));
		}
		else
		{
			while (precision-- > (int)ft_strlen(p))
			{
				j++;
				ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(p, 1);
			return (j + ft_strlen(p));
		}
}

int		ft_no_flag(char conv, int width, int precision, va_list list)
{
	if (conv == 'c')
		return (ft_manage_norm_c(width, list));
	else if (conv == 'p')
		return (ft_manage_norm_p(width, list));
	else if (conv == 's')
		return (ft_manage_norm_s(width, precision, list));
	else if (conv == 'd' || conv == 'i')
		return (ft_manage_norm_di(width, precision, list));
	else if (conv == 'x')
		return (ft_manage_norm_x(width, precision, list));
	else if (conv == 'X')
		return (ft_manage_norm_X(width, precision, list));
	else if (conv == 'u')
		return (ft_manage_norm_u(width, precision, list));
	return (0);
}