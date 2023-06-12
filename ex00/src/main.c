/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:44:21 by bhildebr          #+#    #+#             */
/*   Updated: 2023/06/11 21:51:17 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/error/error.h"
#include "../libs/number/number.h"
#include "../libs/file/file.h"

int	main(int argc, char **argv)
{
	int		err;
	char	*number_str;
	char	*dict;

	err = 0;
	number_str = 0;
	dict = 0;
	if (argc == 2)
	{
		err = number_parse(argv[1], &number_str);
		if (err != 0)
		{
			error_print(err);
			free(number_str);
			return (0);
		}
		err = file_read_as_string("./data/numbers.dict", &dict);
		if (err != 0)
		{
			error_print(err);
			free(number_str);
			free(dict);
			return (0);
		}
		err = number_print_in_words(number_str, dict);
		if (err != 0)
		{
			error_print(err);
			free(number_str);
			free(dict);
			return (0);
		}
	}
	else if (argc == 3)
	{
		err = number_parse(argv[2], &number_str);
		if (err != 0)
		{
			error_print(err);
			free(number_str);
			return (0);
		}
		err = number_print_in_words(number_str, argv[1]);
		if (err != 0)
		{
			error_print(err);
			free(number_str);
			return (0);
		}
	}
	else
	{
		error_print(3);
		return (0);
	}
	return (0);
}
