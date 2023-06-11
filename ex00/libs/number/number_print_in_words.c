/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_print_in_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:06 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 20:30:28 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dict/dict.h"
#include "../std/std.h"
#include <stdio.h>

static int	print_digit(char *dict, char *digit, int sub_group_number)
{
	char	*str;
	char	key[4];
	int		err;

	if (sub_group_number == 0 && digit != '0')
	{
		key[0] = digit;
		key[1] = '\0';
		err = dict_get_value(dict, key, &str);
		if (err != 0)
			return (err);
		std_putstr(str);
	}
	else if (sub_group_number == 1 && digit != '0')
	{
		key[0] = digit;
		// if (digit == '1' && next_digit != '0')
		// 	key[1] = next_digit;
		// else
		// 	key[1] = '0';
		key[1] = ;
		key[2] = '\0';
		printf("next_digit: %c\n", next_digit);
		err = dict_get_value(dict, key, &str);
		if (err != 0)
			return (err);
		std_putstr(str);	
	}
	else if (sub_group_number == 2 && digit != '0')
	{
		key[0] = digit;
		key[1] = '\0';
		key[2] = '0';
		key[3] = '\0';
		err = dict_get_value(dict, key, &str);
		if (err != 0)
			return (err);
		std_putstr(str);
	}
	return (0);
}

static int	print_group(char *dict, int n)
{
	char	*str;
	int		err;

	if (n == 0)
		std_putstr("");
	else if (n == 1)
	{
		err = dict_get_value(dict, "1000", &str);
		if (err != 0)
			return (err);
		std_putstr(str);
	}
	else if (n == 2)
	{
		err = dict_get_value(dict, "1000000", &str);
		if (err != 0)
			return (err);
		std_putstr(str);
	}
	else if (n == 3)
	{
		err = dict_get_value(dict, "1000000000", &str);
		if (err != 0)
			return (err);
		std_putstr(str);
	}
	else
	{
		return (2);
	}
	return (0);
}

static int	print_subgroup(char *dict, char digit, int n)
{
	char	*str;
	int		err;

	if (n == 0)
		std_putstr("");
	else if (n == 1)
		std_putstr("");
	else if (n == 2 && digit != '0')
	{
		err = dict_get_value(dict, "100", &str);
		if (err != 0)
			return (err);
		std_putstr(str);
	}
	else
	{
		return (2);
	}
	return (0);
}

static int	print_final_numbers(char *dict, char *digit, int sub_group_number, int group_number)
{
	print_digit(dict, *digit, sub_group_number);
	print_subgroup(dict, *digit, sub_group_number);
	if (sub_group_number == 0)
	{
		print_group(dict, group_number);
	}
	std_putchar('\n');
	return (0);
}

/*
	groups:
		[0] - ""
		[1] - THOUSAND
		[2] - MILLION
		[3] - BILLION

	sub_groups:
		[0] - ""
		[1] - ""
		[2] - "HUNDRED"
*/
int	number_print_in_words(char *number_str, char *dict)
{
	int				group_number;
	int				sub_group_number;
	char			digit;
	unsigned int	number_str_len;
	unsigned int	i;

	number_str_len = 0;
	while (number_str[number_str_len])
		number_str_len++;
	i = 0;
	while (i < number_str_len)
	{
		digit = number_str[i];
		group_number = (number_str_len - i - 1) / 3;
		sub_group_number = (number_str_len - i - 1) % 3;
		print_final_numbers(dict, &number_str[i], sub_group_number, group_number);
		i++;
	}
	std_putchar('\n');
	return (0);
}
