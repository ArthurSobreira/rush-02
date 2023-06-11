#include <unistd.h>

int	error_print(int code)
{
	if (code == 1)
	{
		write(1, "Error\n", 6);
	}
	else if (code == 2)
	{
		write(1, "Dict Error\n", 11);
	}
	else if (code == 3)
	{
		write(1, "Error :: CHANGE ME\n", 19);
	}
	return (0);
}
