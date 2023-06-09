/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:41:01 by arsobrei          #+#    #+#             */
/*   Updated: 2023/06/09 19:14:02 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	print_long_number(unsigned int, char **dict)
{
	return (0);
}

int	main(void)
{	
	char	*dict[50];

	dict[0] = "zero";
	dict[1] = "one";
	dict[2] = "two";
	dict[3] = "three";
	dict[4] = "four";
	dict[5] = "five";
	dict[6] = "six";
	dict[7] = "seven";
	dict[8] = "eight";
	dict[9] = "nine";
	print_long_number(0, dict);
}