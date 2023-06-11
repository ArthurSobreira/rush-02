/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:41:06 by msarment          #+#    #+#             */
/*   Updated: 2023/06/11 18:00:26 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../std/std.h"

#include <stdio.h>

static int	get_next_key(char **dict, char **key)
{
	unsigned int	max_size;
	unsigned int	current_size;

	max_size = 16;
	current_size = 0;
	*key = (char *)malloc(max_size * sizeof(char));
	if (*key == 0)
		return (3);
	while (**dict >= '0' && **dict <= '9')
	{
		if (current_size == max_size - 1)
			std_realloc_char(key, &max_size);
		(*key)[current_size] = **dict;
		current_size++;
		(*dict)++;
	}
	if (current_size == max_size - 1)
		std_realloc_char(key, &max_size);
	(*key)[current_size] = '\0';
	while (**dict == ' ')
		(*dict)++;
	if (**dict != ':')
		return (2);
	(*dict)++;
	return (0);
}

static int	get_next_value(char **dict, char **value)
{
	unsigned int	max_size;
	unsigned int	current_size;

	while (**dict == ' ')
		(*dict)++;
	max_size = 16;
	current_size = 0;
	*value = (char *)malloc(max_size * sizeof(char));
	while (**dict >= ' ' && **dict <= '~')
	{
		if (current_size == max_size - 1)
			std_realloc_char(value, &max_size);
		(*value)[current_size] = **dict;
		current_size++;
		(*dict)++;
	}
	if (current_size == max_size - 1)
		std_realloc_char(value, &max_size);
	(*value)[current_size] = '\0';
	if (**dict != '\n')
		return (2);
	(*dict)++;
	return (0);
}

int	dict_get_value(char *dict, char *key, char **value)
{
	int					err;
	unsigned int		len;
	char				*current_key;
	char				*current_value;

	while (1)
	{
		err = get_next_key(&dict, &current_key);
		if (err != 0)
			return (err);
		err = get_next_value(&dict, &current_value);
		if (err != 0)
			return (err);
		if (std_strcmp(key, current_key) == 0)
		{
			err = std_strlen(current_value, &len);
			if (err != 0)
				return (err);
			*value = (char *)malloc(len * sizeof(char));
			std_strcpy(*value, current_value);
			free(current_key);
			free(current_value);
			return (0);
		}
		free(current_key);
		free(current_value);
	}
	return (0);
}
