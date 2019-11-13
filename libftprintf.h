/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:31 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/13 22:48:26 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

char		*ft_strrev(char *str);
int			ft_len(long long nb);
char		*ft_upper(char *str);
char		*ft_hex(unsigned long long nb);
int			ft_printf(const char *s, ...);
int			ft_flag_minus(char conv, int width, int precision, va_list list);
int			ft_flag_zero(char conv, int width, int precision, va_list list);
int			ft_no_flag(char conv, int width, int precision, va_list list);
#endif
