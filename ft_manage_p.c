/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 04:28:41 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/21 04:52:39 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_manage_minus_p(t_combo *foo, va_list list)
{
	int		i;
	int		len;
	char	*p;

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

int			ft_manage_zero_p(t_combo *foo, va_list list)
{
	int		i;
	char	*p;

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

int			ft_manage_norm_p(t_combo *foo, va_list list)
{
	int		i;
	char	*p;

	i = 0;
	if (!foo->width && !foo->precision)
	{
		p = ft_strdup("0x");
		ft_putstr_fd(p, 1);
		free(p);
		return (ft_strlen(p));
	}
	if (foo->flag == 1)
		p = ft_strdup("0x");
	else
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

int			ft_manage_simple_p(va_list list)
{
	char	*p;
	int		len;

	p = ft_hex((size_t)va_arg(list, void*));
	if (p == NULL)
		p = ft_strdup("0x0");
	else
		p = ft_strjoin("0x", p);
	len = ft_strlen(p);
	ft_putstr_fd(p, 1);
	return (len);
}
