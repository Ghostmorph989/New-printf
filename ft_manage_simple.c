/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:27:58 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/22 07:22:22 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern char conv;

char		ft_search_conv(const char *s)
{
	int i;

	i = 0;
	while ((ft_isdigit(s[i]) || s[i] == 42 || s[i] == '.' ||
				s[i] == '0' || s[i] == '-') && s[i] != '\0')
		i++;
	return (s[i]);
}

int			ft_manage_simple(va_list list)
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
		return (ft_manage_simple_xx(list));
	else if (conv == 'u')
		return (ft_manage_simple_u(list));
	return (0);
}
