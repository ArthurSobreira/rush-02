#include "hash_table.h"

/*
	AND hash with capacity-1 to ensure it's within entries array
*/
int	ht_set_entry(t_ht_entry *entries, t_size capacity, const char *key, char *value, t_size *plength)
{
	unsigned long long int	hash;
	t_size					index;
	int						err;

	err = hash_key(key, &hash);
	if (err != 0)
		return (err);
	index = (t_size)(hash & (unsigned long long int)(capacity - 1));
	while (entries[index].key != 0)
	{
		if()
	}
}
