#include <stdio.h>

/*
	groups:
		[0] - ""
		[1] - THOUSAND
		[2] - MILLION
		[3] - BILLION

	sub_groups:
		[0] - ""
		[1] - ""
		[2] - "HUNDRED"
*/
int	number_print_in_words(char *number_str, char *dict)
{
	int				group_number;
	int				sub_group_number;
	unsigned int	number_str_len;
	unsigned int	i;

	number_str_len = 0;
	while(number_str[number_str_len])
		number_str_len++;
	i = 0;
	while(i < number_str_len)
	{
		group_number = (number_str_len - i - 1) / 3;
		sub_group_number = (number_str_len - i - 1) % 3;

		// TODO

		i++;
	}
	return (0);
}
