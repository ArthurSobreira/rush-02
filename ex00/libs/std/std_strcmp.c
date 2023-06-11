/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:47 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 17:42:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	std_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == '\0')
		{
			return (0);
		}
	}
	return ((unsigned char)(*s1) - (unsigned char)*(s2 - 1));
}