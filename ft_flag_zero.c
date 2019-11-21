/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:46:45 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/21 07:10:29 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_redirection(char conv, t_combo *foo, va_list list)
{
	if (conv == 'c')
		return (ft_manage_zero_c(foo, list));
	else if (conv == 'p')
		return (ft_manage_zero_p(foo, list));
	else if (conv == 'd' || conv == 'i')
		return (ft_manage_zero_di(foo, list));
	else if (conv == 'x')
		return (ft_manage_zero_x(foo, list));
	else if (conv == 'X')
		return (ft_manage_zero_xx(foo, list));
	else if (conv == 'u')
		return (ft_manage_zero_u(foo, list));
	return (0);
}

int			ft_flag_zero(char conv, t_combo *foo, va_list list)
{
	if (foo->precision == 0)
		return (ft_redirection(conv, foo, list));
	else
	{
		if (conv == 'c')
			return (ft_manage_norm_c(foo, list));
		else if (conv == 'p')
			return (ft_manage_norm_p(foo, list));
		else if (conv == 'd' || conv == 'i')
			return (ft_manage_norm_di(foo, list));
		else if (conv == 'x')
			return (ft_manage_norm_x(foo, list));
		else if (conv == 'X')
			return (ft_manage_norm_xx(foo, list));
		else if (conv == 'u')
			return (ft_manage_norm_u(foo, list));
	}
	return (0);
}
