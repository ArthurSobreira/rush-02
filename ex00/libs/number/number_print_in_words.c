/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_print_in_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:06 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 16:54:45 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../dict/dict.h"

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
	// int				group_number;
	// int				sub_group_number;
	// unsigned int	number_str_len;
	// unsigned int	i;

	// number_str_len = 0;
	// while (number_str[number_str_len])
	// 	number_str_len++;
	// i = 0;
	// while (i < number_str_len)
	// {
	// 	group_number = (number_str_len - i - 1) / 3;
	// 	sub_group_number = (number_str_len - i - 1) % 3;

	// 	// TODO

	// 	i++;
	// }
	printf("inside number_print_in_words\n");
	printf("number_str:\t%s\n", number_str);
	printf("dict:\t%s\n", dict);

	printf("---------------------------------------\n");
	char *value;
	dict_get_value(dict, "40", &value);
	printf("key: 40 - value: %s\n", value);
	
	return (0);
}
