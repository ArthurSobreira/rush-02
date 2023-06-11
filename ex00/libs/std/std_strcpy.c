int	std_strcpy(char *dest, char *src)
{
	while(*src)
		*dest++ = *src++;
	*dest = '\0';
	return (0);
}
