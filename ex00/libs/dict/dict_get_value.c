#include <stdlib.h>
#include "../std/std.h"

static int	get_next_key(char **dict, char **key)
{
	unsigned int	max_size;
	unsigned int	current_size;
	char			*aux_str;

	max_size = 16;
	current_size = 0;
	*key = (char *)malloc(max_size * sizeof(char));
	while(**dict >= '1' && **dict <= '9')
	{
		if(current_size == max_size - 1)
		{
			std_realloc_char(*key, &aux_str, max_size, max_size * 2);
			max_size *= 2;
			*key = aux_str;
		}
		(*key)[current_size] = **dict;
		current_size++;
		(*dict)++;
	}
	if(current_size == max_size - 1)
	{
		std_realloc_char(*key, &aux_str, max_size, max_size * 2);
		max_size *= 2;
		*key = aux_str;
	}
	(*key)[current_size] = '\0';
	while(**dict == ' ')
		(*dict)++;
	if(**dict != ':')
		return (1);
	(*dict)++;
	return (0);
}

static int	get_next_value(char **dict, char **value)
{
	unsigned int	max_size;
	unsigned int	current_size;
	char			*aux_str;

	while(**dict == ' ')
		(*dict)++;
	max_size = 16;
	current_size = 0;
	*value = (char *)malloc(max_size * sizeof(char));
	while(**dict >= ' ' && **dict <= '~')
	{
		if(current_size == max_size - 1)
		{
			std_realloc_char(*value, &aux_str, max_size, max_size * 2);
			max_size *= 2;
			*value = aux_str;
		}
		(*value)[current_size] = **dict;
		current_size++;
		(*dict)++;
	}
	if(current_size == max_size - 1)
	{
		std_realloc_char(*value, &aux_str, max_size, max_size * 2);
		max_size *= 2;
		*value = aux_str;
	}
	(*value)[current_size] = '\0';
	if(**dict != '\n')
		return (1);
	(*dict)++;
	return (0);
}

int dict_get_value(char *dict, char *key, char **value)
{
	int		err;
	char	*current_key;
	char	*current_value;

	while(1)
	{
		err = get_next_key(&dict, &current_key);
		if (err != 0)
			return (err);
		err = get_next_value(&dict, &current_value);
		if (err != 0)
			return (err);
		if (std_strcmp(key, current_key) == 0)
		{
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
