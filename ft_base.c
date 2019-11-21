/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:16:47 by malaoui           #+#    #+#             */
/*   Updated: 2019/11/21 07:08:14 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_strrev(char *str)
{
	int			i;
	int			j;
	char		temp;

	i = 0;
	j = 0;
	if (str != NULL)
		j = ft_strlen(str);
	while (i < j / 2)
	{
		temp = str[j - i - 1];
		str[j - i - 1] = str[i];
		str[i] = temp;
		i++;
	}
	return (str);
}

int				ft_len(size_t nb)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

char			*ft_upper(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char			*ft_hex(size_t nb)
{
	size_t		i;
	size_t j;
	char		*str;
	size_t	temp;

	i = 0;
	j = ft_len(nb);
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		temp = nb % 16;
		if (temp < 10)
			str[i] = temp + '0';
		else
			str[i] = temp + 87;
		nb /= 16;
		i++;
	}
	if (j == 0)
	{
		str[0] = '0';
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
