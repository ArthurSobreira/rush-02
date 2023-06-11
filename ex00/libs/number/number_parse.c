/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:12:38 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 16:29:51 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define UNSIGNED_INT_MAX 4294967295

int	fill_number(char *str, unsigned long long int number, char **number_str);
int	len_number(unsigned int value);

int	number_parse(char *str, char **number_str)
{
	unsigned long long int	number;

	number = 0;
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
	fill_number(str, number, number_str);
	return (0);
}

int	fill_number(char *str, unsigned long long int number, char **number_str)
{
	char	*init;
	int		len;
	int		i;

	init = str;
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		if (number > UNSIGNED_INT_MAX)
			return (1);
		str++;
	}
	len = len_number((unsigned int)number);
	*number_str = (char *)malloc(sizeof(char) * len);
	if (*number_str == 0)
		return (3);
	i = 0;
	while (i < len)
	{
		(*number_str)[i] = *init;
		i++;
		init++;
	}
	(*number_str)[i] = '\0';
	return (0);
}

int	len_number(unsigned int value)
{
	int	i;

	i = 0;
	while (value > 10)
	{
		i++;
		value = value / 10;
	}
	i++;
	return (i);
}
