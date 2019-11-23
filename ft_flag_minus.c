/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:19:58 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/23 16:59:12 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern char g_conv;

int		ft_flag_minus(t_combo *foo, va_list list)
{
	if (g_conv == 'c')
		return (ft_manage_minus_c(foo, list));
	else if (g_conv == 'p')
		return (ft_manage_minus_p(foo, list));
	else if (g_conv == 's')
		return (ft_manage_minus_s(foo, list));
	else if (g_conv == 'd' || g_conv == 'i')
		return (ft_manage_minus_di(foo, list));
	else if (g_conv == 'x')
		return (ft_manage_minus_x(foo, list));
	else if (g_conv == 'X')
		return (ft_manage_minus_xx(foo, list));
	else if (g_conv == 'u')
		return (ft_manage_minus_u(foo, list));
	return (0);
}
