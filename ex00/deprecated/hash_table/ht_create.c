#include <stdlib.h>
#include "hash_table.h"
#define INITIAL_CAPACITY 16

/*
	Allocates space for hash table struct.
	Initializes hash table.
	Allocates space for entries.
	Initializes entries as zero.
*/
int	ht_create(t_ht *table)
{
	int i;

	table = (t_ht *)malloc(sizeof(t_ht));
	if (table == 0)
		return (3);
	table->length = 0;
	table->capacity = INITIAL_CAPACITY;
	table->entries = (t_ht_entry *)malloc(table->capacity * sizeof(t_ht_entry));
	if (table->entries == 0)
	{
		free(table);
		return (3);
	}
	i = 0;
	while(i < table->capacity)
	{
		table->entries[i].key = 0;
		table->entries[i].value = 0;
	}
	return (0);
}
