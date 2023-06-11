#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../std/std.h"

static int read_as_string(int *fd, char **str)
{
	char			*aux_str;
	char			byte;
	unsigned int	max_size;
	unsigned int	current_size;

	max_size = 16;
	current_size = 0;
	*str = (char *)malloc(max_size * sizeof(char));
	if (*str == 0)
		return (3);

	while(read(*fd, &byte, 1))
	{
		if(current_size == max_size - 1)
		{
			std_realloc_char(*str, &aux_str, max_size, max_size * 2);
			max_size *= 2;
			*str = aux_str;
		}
		// printf("byte: %c\tcurrent_size: %u\tmax_size: %u\n", byte, current_size, max_size);
		(*str)[current_size] = byte;
		current_size++;
	}
	if(current_size + 1 > max_size)
	{
		std_realloc_char(*str, &aux_str, max_size, max_size * 2);
		max_size *= 2;
		*str = aux_str;
	}
	(*str)[current_size] = '\0';
	return (0);
}

int file_read_as_string(char *path, char **str)
{
	int				fd;
	int				err;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (3);
	err = read_as_string(&fd, str);
	if (err != 0)
		return err;
	close(fd);
	return (0);
}
