/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read_as_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:05:43 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 16:46:16 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../std/std.h"

static int	read_as_string(int *fd, char **str)
{
	char			byte;
	unsigned int	max_size;
	unsigned int	current_size;

	max_size = 16;
	current_size = 0;
	*str = (char *)malloc(max_size * sizeof(char));
	if (*str == 0)
		return (3);
	while (read(*fd, &byte, 1))
	{
		if (current_size == max_size - 1)
			std_realloc_char(str, &max_size);
		(*str)[current_size] = byte;
		current_size++;
	}
	if (current_size + 1 > max_size)
		std_realloc_char(str, &max_size);
	(*str)[current_size] = '\0';
	return (0);
}

int	file_read_as_string(char *path, char **str)
{
	int				fd;
	int				err;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (3);
	err = read_as_string(&fd, str);
	if (err != 0)
		return (err);
	close(fd);
	return (0);
}
