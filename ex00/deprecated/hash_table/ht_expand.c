#include "hash_table.h"

/*
	Check if the new capacity will overflow.
	Allocate new entries and initialize them.
	Iterate entries, move all non-empty ones to new table's entries.
	Free old entries array and update this table's details.
*/
int	ht_expand(t_ht *table)
{
	t_size		new_capacity;
	t_ht_entry	*new_entries;
	t_size		i;
	t_ht_entry	entry;


	new_capacity = table->capacity * 2;
	if (new_capacity < table->capacity)
		return (3);
	new_entries = (t_ht_entry *)malloc(new_capacity * sizeof(t_ht_entry));
	if (new_entries == 0)
		return (3);
	i = 0;
	while(i < new_capacity)
	{
		new_entries[i].key = 0;
		new_entries[i].value = 0;
		i++;
	}
	i = 0;
	while(i < table->capacity)
	{
		entry = table->entries[i];
		if (entry.key != 0)
		{
			ht_set_entry(new_entries, new_capacity, entry.key, entry.value, 0);
		}
		i++;
	}
	free(table->entries);
	table->entries = new_entries;
	table->capacity = new_capacity;
	return (0);
}
