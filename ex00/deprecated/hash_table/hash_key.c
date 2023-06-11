#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

int hash_key(const char *key, long long unsigned int *hash)
{
	char					*p;

	*hash = FNV_OFFSET;
	p = key;
	while (*p)
	{
		*hash ^= (long long unsigned int)(unsigned char)(*p);
		*hash *= FNV_PRIME;
		p++;
	}
	return (0);
}
