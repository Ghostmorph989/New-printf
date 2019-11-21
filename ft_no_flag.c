/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:47:23 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/21 07:14:12 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_no_flag(char conv, t_combo *foo, va_list list)
{
	if (conv == 'c')
		return (ft_manage_norm_c(foo, list));
	else if (conv == 'p')
		return (ft_manage_norm_p(foo, list));
	else if (conv == 's')
		return (ft_manage_norm_s(foo, list));
	else if (conv == 'd' || conv == 'i')
		return (ft_manage_norm_di(foo, list));
	else if (conv == 'x')
		return (ft_manage_norm_x(foo, list));
	else if (conv == 'X')
		return (ft_manage_norm_xx(foo, list));
	else if (conv == 'u')
		return (ft_manage_norm_u(foo, list));
	return (0);
}