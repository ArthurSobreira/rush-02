#include "hash_table.h"

/*
	First free allocated values and allocated keys.
	Then free entries array and table itself
*/
int	ht_destroy(t_ht *table)
{
	t_size i = 0;

	while(i < table->capacity)
	{
		free(table->entries[i].value);
		free(table->entries[i].key);
		i++;
	}
	free(table->entries);
	free(table);
}
