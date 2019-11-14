/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:17:14 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 12:09:46 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		main(void)
{
	int a = 546;
	int  i;
	int j;


	//ft_printf("Welcome Back To The War %-*p :)\n", 0, &a);
	//ft_printf("Welcome Back To The War |%0*d| :)\n", 20, a);
	i = printf("Welcome Back To The War |%-*.20d| :)\n", 0, a);
	j = ft_printf("Welcome Back To The War |%-*.20d| :)\n", 0, a);
	//ft_printf("Welcome Back To The War %-*.*X :)\n", 11, 15,  a);
	printf("printf : %d || ft_printf : %d", i, j);
//	ft_printf("Welcome Tack To The War :)\n");
//	printf("Welcome Tack To The War :)\n");


	//ft_printf("Welcome Tack To The War :)\n");
	//printf("Welcome Tack To The War :)\n");
	return (0);
}
