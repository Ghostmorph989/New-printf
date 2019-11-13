/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:17:14 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/13 18:41:36 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		main(void)
{
	int a = -546;
	//ft_printf("Welcome Back To The War %-*p :)\n", 0, &a);
	printf("Welcome Back To The War %-*.*X :)\n", 11, 15, a);
	ft_printf("Welcome Back To The War %-*.*X :)\n", 11, 15,  a);

	//ft_printf("Welcome Tack To The War :)\n");
	//printf("Welcome Tack To The War :)\n");


	//ft_printf("Welcome Tack To The War :)\n");
	//printf("Welcome Tack To The War :)\n");
	return (0);
}
