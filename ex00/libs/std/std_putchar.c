#include <unistd.h>

int	std_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
