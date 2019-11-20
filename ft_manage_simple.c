/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:27:58 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/16 20:34:03 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		ft_search_conv(const char *s)
{
	int  i;

	i = 0;
	while ((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.' ||
				s[i] == '0' || s[i] == '-') && s[i] != '\0')
		i++;
	return(s[i]);
}

int			ft_manage_simple_c(va_list list)
{
	
	ft_putchar_fd(va_arg(list, int), 1);
	return (1);
}

int			ft_manage_simple_p(va_list list)
{
	char *p;
	int len;

	p = ft_hex(va_arg(list, long long));
	if (p == NULL)
		p = ft_strdup("0x0");
	else
		p = ft_strjoin("0x", p);
	len = ft_strlen(p);
	ft_putstr_fd(p, 1);
	return (len);
}

int			ft_manage_simple_s(va_list list)
{
	char *p;
	int len;

	p = va_arg(list, char *);
	if (p == NULL)
		p = ft_strdup("(null)");
	len = ft_strlen(p);
	ft_putstr_fd(p, 1);
	return (len);
}

int			ft_manage_simple_di(va_list list)
{
	char *p;
	int len;

	p = ft_itoa(va_arg(list, int));
	len = ft_strlen(p);
	ft_putstr_fd(p, 1);
	return (len);
}

int			ft_manage_simple_x(va_list list)
{
	char *p;
	int len;

	p = ft_hex(va_arg(list, unsigned long long));
	len = ft_strlen(p);
	ft_putstr_fd(p, 1);
	return (len);
}


int			ft_manage_simple_X(va_list list)
{
	char *p;
	int len;

	p = ft_upper(ft_hex(va_arg(list, unsigned long long)));
	ft_putstr_fd(p, 1);
	len = ft_strlen(p);
	return (len);
}

int			ft_manage_simple_u(va_list list)
{
	char *p;
	int len;

	p = ft_itoa(va_arg(list, unsigned int));
	ft_putstr_fd(p, 1);
	len = ft_strlen(p);
	return (len);
}

int			ft_manage_simple(char conv, va_list list)
{
	if (conv == 'c')
		return (ft_manage_simple_c(list));
	else if (conv == 'p')
		return (ft_manage_simple_p(list));
	else if (conv == 's')
		return (ft_manage_simple_s(list));
	else if (conv == 'd' || conv == 'i')
		return (ft_manage_simple_di(list));
	else if (conv == 'x')
		return (ft_manage_simple_x(list));
	else if (conv == 'X')
		return (ft_manage_simple_X(list));
	else if (conv == 'u')
		return (ft_manage_simple_u(list));
	return (0);
}
