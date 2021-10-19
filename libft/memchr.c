#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char*)s;
	while (n != 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
		n--;
	}
	return (0);
}

/*#include <stdio.h>
int	main()
{
	char	b[50] = "Hi my name is";
	int	c = 'm';
	printf("%s\n", ft_memchr(b, c, 8*sizeof(char)));
	printf("%s\n", memchr(b, c, 8*sizeof(char)));
}*/