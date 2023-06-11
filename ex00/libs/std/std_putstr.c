/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:19:24 by arsobrei          #+#    #+#             */
/*   Updated: 2023/06/11 19:19:50 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	std_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	return (0);
}
