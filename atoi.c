/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:23:13 by msarment          #+#    #+#             */
/*   Updated: 2023/06/10 14:16:50 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
	// 48 = '0'
int	check_number(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\f' || str[i] == '\n')
			i++;
		else if (str[i] == '\r' || str[i] == '\v' || str[i] == '\t')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			return (0);
		else
			return (1);
	}
	return (1);
}

char	*clean_array(char *str, int i)
{
	char	*strclean;
	int		cont;

	cont = 0;
	while (str[i] < '0' || str[i] > '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		strclean[cont] = str[i];
		cont++;
	}
	strclean[cont] = '\0';
	return (strclean);
}

// int	atoi(char *str)
// {
// 	unsigned int	number;
// 	int				check;
// 	int				len;
// 	int				i;

// 	i = 0;
// 	check = check_number(str, i);
// 	if (check == 0)
// 	{
// 	}
// }
// "    \n    \t\t  \f \r\r     932912sd102909\n"

int	main(void)
{
	char	*str;
	// int		check;
	int		i;
	char	*str2;

	i = 0;
	str = "\n \n \n 123321";
	// check = check_number(str, i);
	str2 = clean_array(str, i);
	printf("%s", str2);
}
