#include <unistd.h>

int	std_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
	return (0);
}
