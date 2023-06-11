#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef unsigned int t_size;

typedef struct s_ht_entry
{
    char    *key;
    char    *value;
} t_ht_entry;

typedef struct s_ht
{
    t_ht_entry	*entries;
    t_size		capacity;
    t_size		length;
} t_ht;

int	ht_create(t_ht *table);
int	ht_destroy(t_ht *table);
int hash_key(const char *key, long long unsigned int *hash);

#endif
