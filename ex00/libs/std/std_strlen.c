/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:00:42 by bhildebr          #+#    #+#             */
/*   Updated: 2023/06/11 18:00:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	std_strlen(char *str, unsigned int *len)
{
	*len = 0;
	while (str[*len])
		(*len)++;
	return (0);
}
