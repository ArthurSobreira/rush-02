/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:12:38 by msarment          #+#    #+#             */
/*   Updated: 2023/06/10 15:28:46 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define UNSIGNED_INT_MAX 4294967295

int	fill_number(char *str, unsigned long long int number, unsigned int *nbr);

int	atoi(char *str, unsigned int *nbr)
{
	unsigned long long int	number;

	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\f' || *str == '\n' || \
			*str == '\r' || *str == '\v' || *str == '\t')
			str++;
		else if (*str >= '0' && *str <= '9')
			break ;
		else if (*str == '+')
			break ;
		else
			return (1);
	}
	if (*str == '+')
	{
		str++;
		if (*str < '0' || *str > '9')
			return (1);
	}
	fill_number(str, number, nbr);
	return (0);
}

int	fill_number(char *str, unsigned long long int number, unsigned int *nbr)
{
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		if (number > UNSIGNED_INT_MAX)
			return (1);
		str++;
	}
	*nbr = (unsigned int)number;
}

// int	main(void)
// {
// 	char				*str;
// 	unsigned int		number = 0;

// 	str = "    \n \f 23 \f32  ";
// 	atoi(str, &number);
// 	printf("%u\n", number);
// }