#include <stdlib.h>

int	std_realloc_char(char *old_p, char **new_p, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;

	*new_p = (char *)malloc(new_size * sizeof(char));
	if (*new_p == 0)
		return (3);
	i = 0;
	while(i < old_size)
	{
		(*new_p)[i] = old_p[i];
		i++;
	}
	free(old_p);
	return (0);
}
