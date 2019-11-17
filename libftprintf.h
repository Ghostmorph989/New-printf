/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:31 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 11:03:03 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

char		*ft_strrev(char *str);
int			ft_len(unsigned long long nb);
char		*ft_upper(char *str);
char		*ft_hex(unsigned long long nb);
int			ft_printf(const char *s, ...);
int			ft_flag_minus(char conv, int width, int precision, va_list list);
int			ft_flag_zero(char conv, int width, int precision, va_list list);
int			ft_no_flag(char conv, int width, int precision, va_list list);
int		    ft_manage_norm_u(int width, int precision, va_list list);
int		    ft_manage_norm_X(int width, int precision, va_list list);
int		    ft_manage_norm_x(int width, int precision, va_list list);
int		    ft_manage_norm_di(int width, int precision, va_list list);
int		    ft_manage_norm_s(int width, int precision, va_list list);
int	    	ft_manage_norm_p(int width, va_list list);
int		    ft_manage_norm_c(int width, va_list list);
int			ft_manage_simple_c(va_list list);
int			ft_manage_simple_p(va_list list);
int			ft_manage_simple_s(va_list list);
int			ft_manage_simple_di(va_list list);
int			ft_manage_simple_x(va_list list);
int			ft_manage_simple_X(va_list list);
int			ft_manage_simple_u(va_list list);
int			ft_manage_simple(char conv, va_list list);
char		ft_search_conv(const char *s);
#endif
