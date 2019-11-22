/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:19:58 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/22 07:19:37 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern char conv;

int		ft_flag_minus(t_combo *foo, va_list list)
{
	if (conv == 'c')
		return (ft_manage_minus_c(foo, list));
	else if (conv == 'p')
		return (ft_manage_minus_p(foo, list));
	else if (conv == 's')
		return (ft_manage_minus_s(foo, list));
	else if (conv == 'd' || conv == 'i')
		return (ft_manage_minus_di(foo, list));
	else if (conv == 'x')
		return (ft_manage_minus_x(foo, list));
	else if (conv == 'X')
		return (ft_manage_minus_xx(foo, list));
	else if (conv == 'u')
		return (ft_manage_minus_u(foo, list));
	return (0);
}
