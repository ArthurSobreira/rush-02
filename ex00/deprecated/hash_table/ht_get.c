#include "hash_table.h"

int	strcmp(char *s1, char *s2)
{
	while(*s1 == *s2)
		if(*s1 == '\0')
			return (0);
	return (unsigned char)(*s1) - (unsigned char)(*s2);
}

/*
	AND hash with capacity-1 to ensure it's within entries array.
	Loop till we find an empty entry.
*/
int	ht_get(t_ht *table, const char *key, char *value)
{
	unsigned long long int	hash;
	t_size					index;
	int						err;

	err = hash_key(key, hash);
	if (err != 0)
		return (err);
	index = (t_size)(hash & (long long int)(table->capacity - 1));
	while(table->entries[index].key != 0)
	{
		if(strcmp(key, table->entries[index].key) == 0)
		{
			value = table->entries[index].value;
			return (0);
		}
		index++;
		if (index >= table->capacity)
			index = 0;
	}
	return (3);
}
