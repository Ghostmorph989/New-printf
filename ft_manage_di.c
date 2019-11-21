/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 04:31:48 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/21 08:02:09 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_checkprint(t_combo *foo, char *p, int *i, int j)
{
	if (((foo->flag) == 0) || ((ft_atoi(p) != 0) || (foo->precision != 0)))
		ft_putstr_fd(p, 1);
	else if (((foo->flag) == 1 || (ft_atoi(p) != 0)) && j != 0)
		*i -= 1;
}

static int	ft_checkmdi(t_combo *foo, char *p, int len)
{
	int j;
	int i;

	j = 0;
	i = 0;
	j = (foo->width);
	if (p[0] == '-')
	{
		ft_putchar_fd('-', 1);
		p = p + 1;
	}
	ft_checkprint(foo, p, &i, j);
	if ((foo->width) != 0 && (foo->precision) == 0 
			&& foo->flag == 1 && ft_atoi(p) == 0)
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

void	ft_checkm(t_combo *foo, char **p, int *len, int *i)
{
	int j;

	j = 0;
	ft_putchar_fd('-', 1);
	*p += 1;
	if ((foo->precision) < (foo->width))
	{
		(foo->precision)++;
		*i -= 1;
	}
	else
		*len -= 1;
	*i += 1;
}

static int	ft_checkmpdi(t_combo *foo, char *p, int len)
{
	int j;
	int i;

	i = 0;
	j = 0;
	j = (foo->width);
	if ((foo->precision) < len)
		(foo->precision)++;
	if (p[0] == '-')
		ft_checkm(foo, &p, &len, &i);
	while ((foo->precision)-- > len)
	{
		ft_putchar_fd('0', 1);
		i++;
		j--;
	}
	ft_checkprint(foo, p, &i, j);
	if ((foo->width) != 0 && (foo->flag) == 1 && ft_atoi(p) == 0)
		ft_putchar_fd(' ', 1);
	while (--j > (foo->precision))
	{
		i++;
		ft_putchar_fd(' ', 1);
	}
	return (i + len);
}

int			ft_manage_minus_di(t_combo *foo, va_list list)
{
	char	*p;
	int		len;

	p = ft_itoa(va_arg(list, int));
	len = ft_strlen(p);
	if ((foo->precision) == 0)
		return (ft_checkmdi(foo, p, len));
	else
		return (ft_checkmpdi(foo, p, len));
	return (0);
}

int			ft_manage_simple_di(va_list list)
{
	char	*p;
	int		len;

	p = ft_itoa(va_arg(list, int));
	len = ft_strlen(p);
	ft_putstr_fd(p, 1);
	return (len);
}
