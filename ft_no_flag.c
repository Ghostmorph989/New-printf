/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:47:23 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/23 17:29:18 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern char g_conv;

void		ft_checkprint(t_combo *foo, char *p, int *i, int j)
{
	if (((foo->flag) == 0) || ((ft_atoi(p) != 0) || (foo->precision != 0)))
		ft_putstr_fd(p, 1);
	else if (((foo->flag) == 1 || (ft_atoi(p) != 0)) && j != 0)
		*i -= 1;
}

int		ft_no_flag(t_combo *foo, va_list list)
{
	if (g_conv == 'c')
		return (ft_manage_norm_c(foo, list));
	else if (g_conv == 'p')
		return (ft_manage_norm_p(foo, list));
	else if (g_conv == 's')
		return (ft_manage_norm_s(foo, list));
	else if (g_conv == 'd' || g_conv == 'i')
		return (ft_manage_norm_di(foo, list));
	else if (g_conv == 'x')
		return (ft_manage_norm_x(foo, list));
	else if (g_conv == 'X')
		return (ft_manage_norm_xx(foo, list));
	else if (g_conv == 'u')
		return (ft_manage_norm_u(foo, list));
	return (0);
}
