/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:44:21 by bhildebr          #+#    #+#             */
/*   Updated: 2023/06/11 22:08:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/error/error.h"
#include "../libs/number/number.h"
#include "../libs/file/file.h"

void	solve_for_3_args(char **argv, char *number_str)
{
	int	err;

	err = number_parse(argv[2], &number_str);
	if (err != 0)
	{
		error_print(err);
		free(number_str);
		return ;
	}
	err = number_print_in_words(number_str, argv[1]);
	if (err != 0)
	{
		error_print(err);
		free(number_str);
		return ;
	}
}

void	solve_for_2_args(char **argv, char *number_str, char *dict)
{
	int	err;

	err = number_parse(argv[1], &number_str);
	if (err != 0)
	{
		error_print(err);
		free(number_str);
		return ;
	}
	err = file_read_as_string("./data/numbers.dict", &dict);
	if (err != 0)
	{
		error_print(err);
		free(number_str);
		free(dict);
		return ;
	}
	err = number_print_in_words(number_str, dict);
	if (err != 0)
	{
		error_print(err);
		free(number_str);
		free(dict);
		return ;
	}
}

int	main(int argc, char **argv)
{
	char	*number_str;
	char	*dict;

	number_str = 0;
	dict = 0;
	if (argc == 2)
		solve_for_2_args(argv, number_str, dict);
	else if (argc == 3)
		solve_for_3_args(argv, number_str);
	else
		error_print(3);
	return (0);
}
