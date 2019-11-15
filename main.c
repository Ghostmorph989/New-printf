/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:17:14 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/14 18:17:13 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		main(void)
{
	int  i;
	int j;
	int a = 1;
	//ft_printf("Welcome Back To The War %-*p :)\n", 0, &a);
	//ft_printf("Welcome Back To The War |%0*d| :)\n", 20, a);
	//ft_printf("Welcome Back To The War %-*.*X :)\n", 11, 15,  a);
	i = printf("|%15.0d|\n", a);
	j = ft_printf("|%15.0d|\n", a);
	ft_printf("ft_printf : %d || printf : %d\n", j, i);	
	/*j = printf("|%0*s|\n", 5, a);
	i = ft_printf("|%0*s|\n",5,a);
	ft_printf("ft_printf : %d || printf : %d\n", i, j);	
*/
//	ft_printf("Welcome Tack To The War :)\n");
//	printf("Welcome Tack To The War :)\n");


	//ft_printf("Welcome Tack To The War :)\n");
	//printf("Welcome Tack To The War :)\n");
	return (0);
}
