/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:31 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/21 07:17:35 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_combo
{
	int width;
	int precision;
	int flag;
	int cc;
}				t_combo;

char			*ft_strrev(char *str);
int				ft_len(size_t nb);
char			*ft_upper(char *str);
char			*ft_hex(size_t nb);
int				ft_printf(const char *s, ...);
int				ft_flag_minus(char conv, t_combo *foo, va_list list);
int				ft_flag_zero(char conv, t_combo *foo, va_list list);
int				ft_no_flag(char conv, t_combo *foo, va_list list);
int				ft_manage_simple(char conv, va_list list);
char			ft_search_conv(const char *s);
int				ft_manage_minus_c(t_combo *foo, va_list list);
int				ft_manage_zero_c(t_combo *foo, va_list list);
int				ft_manage_norm_c(t_combo *foo, va_list list);
int				ft_manage_simple_c(va_list list);
int				ft_manage_minus_s(t_combo *foo, va_list list);
int				ft_manage_norm_s(t_combo *foo, va_list list);
int				ft_manage_simple_s(va_list list);
int				ft_manage_minus_p(t_combo *foo, va_list list);
int				ft_manage_zero_p(t_combo *foo, va_list list);
int				ft_manage_norm_p(t_combo *foo, va_list list);
int				ft_manage_simple_p(va_list list);
int				ft_manage_minus_di(t_combo *foo, va_list list);
int				ft_manage_zero_di(t_combo *foo, va_list list);
int				ft_manage_norm_di(t_combo *foo, va_list list);
int				ft_manage_simple_di(va_list list);
int				ft_manage_minus_x(t_combo *foo, va_list list);
int				ft_manage_zero_x(t_combo *foo, va_list list);
int				ft_manage_norm_x(t_combo *foo, va_list list);
int				ft_manage_simple_x(va_list list);
int				ft_manage_minus_xx(t_combo *foo, va_list list);
int				ft_manage_zero_xx(t_combo *foo, va_list list);
int				ft_manage_norm_xx(t_combo *foo, va_list list);
int				ft_manage_simple_xx(va_list list);
int				ft_manage_minus_u(t_combo *foo, va_list list);
int				ft_manage_zero_u(t_combo *foo, va_list list);
int				ft_manage_norm_u(t_combo *foo, va_list list);
int				ft_manage_simple_u(va_list list);
#endif
