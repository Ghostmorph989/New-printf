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


int		main(int ac, char **argv)
{
	int	i;
	int	j;
	int a = -5614351;
	//ft_printf("Welcome Back To The War %-*p :)\n", 0, &a);
	//ft_printf("Welcome Back To The War |%0*d| :)\n", 20, a);
	//ft_printf("Welcome Back To The War %-*.*X :)\n", 11, 15,  a);
	// ft_printf("\t\tTEST 1\t\t\t\t\t\t\t\n");
	// i = printf("%.2s %02d %015.d %%d %3.2s,\n", "ABC", 100, 546, "gdfgsd");
	// j = ft_printf("%.2s %02d %015.d %%d %2.2s,\n", "ABC", 100, 546,"gdfgsd");
	// ft_printf("ft_printf : %d\n printf    : %d\n", j, i);

	// ft_printf("\t\tTEST 2\n");
	// j = ft_printf("1<ultimate4 %*.*x %*.*X>\n",  1, 50, 5000, 1,100, 10 - 0x10000000A);
	// i = printf("2<ultimate4 %*.*x %*.*X>\n",  1, 50, 5000, 1, 1, 0);	
	// ft_printf("ft_printf : %d || printf    : %d\n", j, i);

	printf("%s\n%x\n",ft_hex(-18446), -18446);


	// ft_printf("\t\tTEST 3\t\t\t\t\t\t\t\n");
	// i = printf("|%02d|\n", 100);
	// j = ft_printf("|%02d|\n", 100);	
	// ft_printf("ft_printf : %d\nprintf    : %d\n", j, i);

	// ft_printf("\t\tTEST 4\t\t\t\t\t\t\t\n");
	// i = printf("|%015.d|\n", 546);
	// j = ft_printf("|%015.d|\n", 546);	
	// ft_printf("ft_printf : %d\nprintf    : %d\n", j, i);

	// ft_printf("\t\tTEST 5\t\t\t\t\t\t\t\n");
	// i = printf("|%020u|\n", a);
	// j = ft_printf("|%020u|\n", a);
	// ft_printf("ft_printf : %d\nprintf    : %d\n", j, i);
//	ft_printf("Welcome Tack To The War :)\n");
//	printf("Welcome Tack To The War :)\n");


	//ft_printf("Welcome Tack To The War :)\n");
	//printf("Welcome Tack To The War :)\n");
	return (0);
}
