/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:05:24 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 20:59:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	error_print(int code)
{
	if (code == 1)
	{
		write(1, "Error\n", 6);
	}
	else if (code == 2)
	{
		write(1, "Dict Error\n", 11);
	}
	else if (code == 3)
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
