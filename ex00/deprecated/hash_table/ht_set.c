#include "hash_table.h"

/*
	If length will exceed half of current capacity, expand it.
	Set entry and update length.
*/
int	ht_set(t_ht *table, const char *key, char *value)
{
	int err;

	if (table->length >= table->capacity / 2)
	{
		err = ht_expand(table);
		if (err != 0)
			return (err);
	}

	err = ht_set_entry(table->entries, table->capacity, key, value, &table->length);
}
