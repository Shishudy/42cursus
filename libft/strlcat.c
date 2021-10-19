unsigned long int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	i = 0;
	while (dest[a])
		a++;
	while (src[b])
		b++;
	if (size == 0)
		return (b);
	if (size <= a)
		return (size + b);
	while (size && i < (size - a - 1) && src[i])
	{
		dest[a + i] = src[i];
		i++;
	}
	dest[a + i] = '\0';
	return (b + a);
}

#include <string.h>
#include <stdio.h>

int	main()
{
	const char src1[10]	= "abc123";
	char dest1[10]   = "12345";

	char src[10]	= "abc123";
	char dest[10]	= "12345";
	printf("%lu ", ft_strlcat(dest, src, 10));
	printf("%s ", dest);
	printf("%lu ", strlcat(dest1, src1, 10));
	printf("%s ", dest1);
}