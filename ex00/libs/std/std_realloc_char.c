/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_realloc_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:30:17 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 16:30:39 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	std_realloc_char(char **p, unsigned int *size)
{
	unsigned int	i;
	char			*p_aux;

	p_aux = (char *)malloc(*size * 2 * sizeof(char));
	if (p_aux == 0)
		return (3);
	i = 0;
	while (i < *size)
	{
		p_aux[i] = (*p)[i];
		i++;
	}
	free(*p);
	*p = p_aux;
	*size = *size * 2;
	return (0);
}
