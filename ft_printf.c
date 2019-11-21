/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:19:51 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/21 01:31:20 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_calcul_width_precision(const char *s, t_combo *foo, va_list list)
{
	int i;

	i = 0;
	(foo->precision) = 0;
	(foo->width) = 0;
	(foo->flag) = 0;
	(foo->cc) = 0;
	if (ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.')
	{
		if (s[i] == 42)
			(foo->width) = va_arg(list, int);
		else
			(foo->width) = ft_atoi(s + i);
		while ((ft_isdigit(s[i]) || (s[i] == 42)) && (s[i] != '\0'))
			i++;
		if (s[i] == '.')
		{
			i++;
			(foo->flag) = 1;
		}
		if (s[i] == 42)
		{
			(foo->precision) = va_arg(list, int);
			if ((foo->precision) == 0)
				(foo->flag) = 1;
			else
				(foo->flag) = 0;
		}
		else if (ft_isdigit(s[i]))
		{
			(foo->precision) = ft_atoi(s + i);
			if ((foo->precision) == 0)
				(foo->flag) = 1;
			else
				(foo->flag) = 0;
		}
		while ((ft_isdigit(s[i]) || (s[i] == 42) || s[i] == '.') &&  (s[i] != '\0'))
			i++;
		if ((foo->precision) < 0)
			(foo->precision) = -1;
	}
	return (i);
}


int			ft_manage(const char *s, int *pos, va_list list)
{
	int i;
	char conv;
	int cpt;
	t_combo foo;
	int j;

	i = 0;
	j = 0;
	cpt = 0;
	conv  = ft_search_conv(s);
	if (s[i] == '-' && conv  != '%')
	{
		i++;
		while ((s[i] == '-' || s[i] == '0') && s[i] != '\0')
			i++;
		j = ft_calcul_width_precision(s + i, &foo, list) - 1;
		i++;
		*pos += i + j + 1;
		if (foo.width < 0)
			foo.width *= -1;
		cpt = ft_flag_minus(conv, &foo, list);
	}
	else if (s[i] == '0' && conv  != '%')
	{
		while (s[i] == '0' && s[i] != '\0')
			i++;
		if (s[i] == '-')
		{
			while ((s[i] == '-') && s[i] != '\0')
				i++;
			j = ft_calcul_width_precision(s + i, &foo, list);
			i++;
			*pos += i + j;
			if (foo.width < 0)
				foo.width *= -1;
			cpt = ft_flag_minus(conv, &foo, list);
			return (cpt);
		}
		else
		{
			j = ft_calcul_width_precision(s + i, &foo, list);
			if (foo.width < 0)
			{
				foo.width *= -1;
				cpt = ft_flag_minus(conv, &foo, list);
				i++;
				*pos += i + j;
				return (cpt);
			}
			i++;
			*pos += i + j;
			cpt = ft_flag_zero(conv, &foo, list);
		}
	}
	else if (((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.')) && s[i] != '0' && conv  != '%')
	{
		i = ft_calcul_width_precision(s + i, &foo, list);
		*pos += i + 1;
		if (foo.width < 0)
		{
			foo.width *= -1;
			cpt = ft_flag_minus(conv, &foo, list);
		}
		else
			cpt = ft_no_flag(conv, &foo, list);
	}
	else if (conv  == '%')
	{
		conv = 'c';
		if (s[i] == '-')
		{
			i++;
			i = ft_calcul_width_precision(s + i, &foo, list);
			i++;
			*pos += i + 1;
			foo.cc = 1;
			cpt = ft_flag_minus(conv, &foo, list);
		}
		else if (s[i] == '0')
		{
			i++;
			i = ft_calcul_width_precision(s + i, &foo, list);
			i++;
			*pos += i + 1;
			foo.cc = 1;
			cpt = ft_flag_zero(conv, &foo, list);
		}
		else if (ft_isdigit(s[i]))
		{
			i = ft_calcul_width_precision(s + i, &foo, list);
			*pos += i + 1;
			foo.cc = 1;
			cpt = ft_no_flag(conv, &foo, list);
		}
		else
		{
			ft_putchar_fd('%', 1);
			i = ft_calcul_width_precision(s + i, &foo, list);
			cpt = i - 1;
			*pos += i + 1;
		}
	}
	else if (conv == 'c' || conv == 's' || conv == 'p' || conv == 'x'
	|| conv == 'X' || conv == 'u' || conv == 'd' || conv == 'i')
	{
		*pos += 1;
		cpt = ft_manage_simple(conv, list);
	}
	return (cpt);
}

int			ft_printf(const char *s, ...)
{
	int		i;
	va_list	list;
	int	cpt;
	int		j;

	va_start(list, s);
	i = 0;
	j = 0;
	cpt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i += 2;
			cpt += 1;
		}
		else if (s[i] == '%')
		{
			i++;
			cpt += ft_manage((char *)(s + i), &i, list);
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			cpt++;
		}
	}
	va_end(list);
	return (cpt);
}
