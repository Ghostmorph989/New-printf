/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:19:51 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/22 18:02:18 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char conv;


int ft_minus(char *s,va_list list, t_combo *foo, int* pos)
{
	int j;

	j = 0;
	*pos += 1;
	while ((s[*pos] == '-') && s[*pos] != '\0')
		*pos += 1;
	j = ft_calcul_width_precision(s + *pos, foo, list);
	*pos += 1;
	*pos += j;
	if (foo->width < 0)
		foo->width *= -1;
	return (ft_flag_minus(foo, list));
}

int			ft_for_minus(char *s, va_list list, t_combo *foo, int *pos)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	cpt = ft_minus((char *)s, list, foo , &i);
	*pos += i;
	return (cpt);
}

int			ft_for_else(char *s, int *pos, t_combo *foo, va_list list)
{
	int j;

	j = ft_calcul_width_precision(s, foo, list);
	*pos += j + 1;
	if (foo->width < 0)
	{
		foo->width *= -1;
		return (ft_flag_minus(foo, list));
	}
	else if (foo->flag == 1 && foo->precision == 0)
		return (ft_no_flag(foo, list));
	return (ft_flag_zero(foo, list));
}

int			ft_for_norm(char *s, int *pos, t_combo *foo, va_list list)
{
	int j;

		j = ft_calcul_width_precision(s, foo, list);
		*pos += j + 1;
		if (foo->width < 0)
		{
			foo->width *= -1;
			return (ft_flag_minus(foo, list));
		}
		else
			return (ft_no_flag(foo, list));
}

int			ft_percent_minus(char *s, int *pos, t_combo *foo, va_list list)
{
	int j;

	j = ft_calcul_width_precision(s, foo, list);
	*pos += j + 1;
	foo->cc = 1;
	return (ft_flag_minus(foo, list));
}

int			ft_percent_zero(char *s, int *pos, t_combo *foo, va_list list)
{
	int j;

	j = ft_calcul_width_precision(s, foo, list);
	*pos += j + 1;
	foo->cc = 1;
	return (ft_flag_zero(foo, list));
}

int			ft_percent_digit(char *s, int *pos, t_combo *foo, va_list list)
{
	int j;

	j = ft_calcul_width_precision(s, foo, list);
	*pos += j + 1;
	foo->cc = 1;
	return (ft_no_flag(foo, list));
}

int			ft_percent_else(char *s, int *pos, t_combo *foo, va_list list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[i] == '.' && s[i] != '\0')
		i++;
	ft_putchar_fd('%', 1);
	j = ft_calcul_width_precision(s + i, foo, list);
	*pos += i + j;
	if (foo->flag == 0 && foo->width == 0)
		j -= 1;
	return (j);
}

int			ft_simple_conv(va_list list, int *pos)
{
	*pos += 1;
	return (ft_manage_simple(list));
}

int			ft_return(char *s, va_list list, int *pos, t_combo *foo)
{
	int i;

	i = 0;
	while (s[i] == '0' && s[i] != '\0')
			i++;
	if (s[i--] == '-')
		return (ft_for_minus((char *)s + i, list, foo, pos));
	else
		return (ft_for_else((char *)s + i, pos, foo, list));
	return (0);
}
int 		ft_percent_return(char *s, int *pos, t_combo *foo, va_list list)
{
	int i;

	i = 0;
	conv = 'c';
		if (s[i] == '-')
			return (ft_percent_minus((char *)s + 1, pos, foo, list));
		else if (s[i] == '0')
			return (ft_percent_zero((char *)s + 1, pos, foo, list));
		else if (ft_isdigit(s[i]))
			return (ft_percent_digit((char *)s, pos, foo, list));
		else
			return (ft_percent_else((char *)s, pos, foo, list));
	return (0);
}

int			ft_manage(const char *s, int *pos, va_list list)
{
	int i;
	t_combo foo;

	i = 0;
	conv  = ft_search_conv(s);
	ft_init(&foo);
	if (s[i] == '-' && conv  != '%')
		return (ft_for_minus((char *)s + i, list, &foo, pos));
	else if (s[i] == '0' && conv  != '%')
		return (ft_return((char *)s + i, list, pos, &foo));
	else if (((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.')) 
			&& s[i] != '0' && conv  != '%')
		return (ft_for_norm((char *)s + i, pos, &foo, list));
	else if (conv  == '%')
		return (ft_percent_return((char *)s + i, pos, &foo, list));
	else if (conv == 'c' || conv == 's' || conv == 'p' || conv == 'x'
	|| conv == 'X' || conv == 'u' || conv == 'd' || conv == 'i')
		return (ft_simple_conv(list, pos));
	return (0);
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