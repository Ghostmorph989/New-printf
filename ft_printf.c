/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:19:51 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/13 23:13:04 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_calcul_width_precision(const char *s, int *width, int *precision, va_list list)
{
	int i;

	i = 0;
	if (ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.')
	{
		if (s[i] == 42)
			*width = va_arg(list, int);
		else
			*width = ft_atoi(s + i);	
		while ((ft_isdigit(s[i]) && ( s[i] != '\0')) || (s[i] == 42))
			i++;
		if (s[i] == '.')
			i += 1;
		if (s[i] == 42)
			*precision = va_arg(list, int);
		else
			*precision = ft_atoi(s + i);		
		while ((ft_isdigit(s[i]) && (s[i] != '\0')) || (s[i] == 42))
			i++;
	}
}

char		ft_search_conv(const char *s)
{
	int  i;

	i = 0;
	while ((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.' || 
				s[i] == '0' || s[i] == '-'))
		i++;
	return(s[i]);
}
void		ft_manage(const char *s, int *pos, va_list list)
{
	int i;
	int width;
	int precision;
	char conv;

	i = 0;
	width = 0;
	precision = 0;
	conv  = ft_search_conv(s);
	if (s[i] == '-')
	{
		i++;
		ft_calcul_width_precision(s + i, &width, &precision, list);
		while ((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.'))
			i++;
		*pos += i + 1;
		ft_flag_minus(conv, width, precision, list);
	}
	else if (s[i] == '0')
	{
		i++;
		ft_calcul_width_precision(s + i, &width, &precision, list);
		while ((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.'))
			i++;
		*pos += i + 1;
		ft_flag_zero(conv, width, precision, list);
	}
	else
	{
		ft_calcul_width_precision(s + i, &width, &precision, list);
		while ((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.'))
			i++;
		*pos += i + 1;
		ft_no_flag(conv, width, precision, list);
	}
}

int			ft_printf(const char *s, ...)
{
	int		i;
	va_list	list;
	int		cpt;

	va_start(list, s);
	i = 0;
	cpt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_manage((char *)(s + i), &i, list);
		}
		else
			ft_putchar_fd(s[i++], 1);
	}
	va_end(list);
	return (cpt);
}
