/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:44:21 by bhildebr          #+#    #+#             */
/*   Updated: 2023/06/11 04:44:56 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/error/error.h"
#include "../libs/number/number.h"
#include "../libs/file/file.h"

#include <stdio.h>
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
			return (0);
		}
		printf("The number was parsed and it is %s!\n", number_str);
		err = file_read_as_string("./data/numbers.dict", &dict);
		if (err != 0)
		{
			error_print(err);
			return (0);
		}
		printf("The file was read and it is:\n%s\n", dict);
		err = number_print_in_words(number_str, dict);
		if (err != 0)
		{
			error_print(err);
			return (0);
		}
		printf("The number was printed in words!\n");
		printf("Don't forget to free every allocated memory.\n");
	}
	else if(argc == 3)
	{
		// err = number_parse(argv[2], number_str);
		// if (err != 0)
		// {
		// 	error_print(err);
		// 	return (0);
		// }
		// err = number_print_in_words(number_str, argv[1]);
		// if (err != 0)
		// {
		// 	error_print(err);
		// 	return (0);
		// }
	}
	else
	{
		error_print(3);
		return (0);
	}
	return (0);
}
