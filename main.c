/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:17:14 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/22 23:42:39 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		main(void)
{
	int	i;
	int	j;
	// int a = -5614351;
	// ft_printf("Welcome Back To The War %-*p :)\n", 0, &a);
	// ft_printf("Welcome Back To The War |%0*d| :)\n", 20, a);
	// printf("Welcome Back To The War |%0*d| :)\n", 20, a);
	// ft_printf("\t\tTEST 1\t\t\t\t\t\t\t\n");
	// i = printf("%.2s %02d %015.d %%d %3.2s,\n", "ABC", 100, 546, "gdfgsd");
	// j = ft_printf("%.2s %02d %015.d %%d %3.2s,\n", "ABC", 100, 546,"gdfgsd");
	// ft_printf("ft_printf : %d\n printf    : %d\n", j, i);

	// ft_printf("\t\tTEST 2\n");
	// j = ft_printf("1<%*.*x dsjkfha sfdls fh fadjsfashf asjhf asdfhalsjhflasjf lasdjf ladjsf adsjf asdljfhasd adsl fadslfj hadsljfh sifjasdjf sfamds  fas fas dfa sd fasd faksd faldflajdfansd fas fna dfa dfas dknf aks aks faksd fk ad fkas bfkas >\n", 1, 50, 5000);
	// i = printf("2<%*.*x dsjkfha sfdls fh fadjsfashf asjhf asdfhalsjhflasjf lasdjf ladjsf adsjf asdljfhasd adsl fadslfj hadsljfh sifjasdjf sfamds  fas fas dfa sd fasd faksd faldflajdfansd fas fna dfa dfas dknf aks aks faksd fk ad fkas bfkas >\n", 1, 50, 5000);	
	// ft_printf("ft_printf : %d || printf    : %d\n", j, i);


	// i = printf("1<***************%*s%*d**************%*u*************>\n", 10, "coucou", 10, 10, -50, 20);
	// j = ft_printf("2<***************%*s%*d**************%*u*************>\n", 10, "coucou", 10, 10, -50, 20);
	// ft_printf("ft_printf : %d || printf : %d\n", j, i);


	ft_printf("\t\tTEST 3\t\t\t\t\t\t\t\n");
	i = printf("1<%*.%>\n", 10);	
	j = ft_printf("2<%*.%>\n", 10);
	ft_printf("ft_printf : %d\n __printf : %d\n", j, i);

	// ft_printf("\t\tTEST 4\t\t\t\t\t\t\t\n");
	// i = printf("<%-12s>\n", "");
	// j = ft_printf("<%-12s>\n","");
	// ft_printf("ft_printf : %d\nprintf    : %d\n", j, i);

	// ft_printf("\t\tTEST 5\t\t\t\t\t\t\t\n");
	// i = printf("|%020u|\n", a);
	// j = ft_printf("|%020u|\n", a);
	// ft_printf("ft_printf : %d\nprintf    : %d\n", j, i);
	// ft_printf("Welcome Tack To The War :)\n");
	// printf("Welcome Tack To The War :)\n");


	// ft_printf("Welcome Tack To The War :)\n");
	// printf("Welcome Tack To The War :)\n");
	return (0);
}
