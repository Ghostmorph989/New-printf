/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:19:51 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 18:07:03 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_calcul_width_precision(const char *s, int *width, int *precision, va_list list)
{
	int i;

	i = 0;
	if (ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.')
	{
		if (s[i] == 42)
			*width = va_arg(list, int);
		else
			*width = ft_atoi(s + i);
		while ((ft_isdigit(s[i]) || (s[i] == 42)) && (s[i] != '\0'))
			i++;
		if (s[i] == '.')
		{
			i += 1;
			*precision = -1;
		}
		if (s[i] == 42)
			*precision = va_arg(list, int);
		else if (ft_isdigit(s[i]))
			*precision = ft_atoi(s + i);
		while ((ft_isdigit(s[i]) || (s[i] == 42) || s[i] == '.') &&  (s[i] != '\0'))
			i++;
		if (*precision < 0)
			*precision = -1;
	}
	//printf("Width :%d || Precision :%d", *width, *precision);
	return (i);
}


int			ft_manage(const char *s, int *pos, va_list list)
{
	int i;
	int width;
	int precision;
	char conv;
	int cpt;

	i = 0;
	cpt = 0;
	width = 0;
	precision = 0;
	conv  = ft_search_conv(s);
	if (s[i] == '-')
	{
		i++;
		i = ft_calcul_width_precision(s + i, &width, &precision, list);
		i++;
		*pos += i + 1;
		cpt = ft_flag_minus(conv, width, precision, list);
	}
	else if (s[i] == '0')
	{
		i++;
		i = ft_calcul_width_precision(s + i, &width, &precision, list);
		i++;
		*pos += i + 1;
		if (width < 0)
		{
			width *= -1;
			cpt = ft_flag_minus(conv, width, precision, list);
		}
		else
			cpt = ft_flag_zero(conv, width, precision, list);
	}
	else if (ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.')
	{
		i = ft_calcul_width_precision(s + i, &width, &precision, list);
		*pos += i + 1;
		if (width < 0)
		{
			width *= -1;
			cpt = ft_flag_minus(conv, width, precision, list);
		}
		else
			cpt = ft_no_flag(conv, width, precision, list);
	}
	else
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
	cpt = 0;
	while (s[i] != '\0')
	{

		if (s[i] == '%' && s[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			cpt++;
		}
		if (s[i] == '%')
		{
			i++;
			cpt = cpt + ft_manage((char *)(s + i), &i, list);
		}
		else
			ft_putchar_fd(s[i++], 1);
		cpt++;
	}
	va_end(list);
	return (cpt - 1);
}