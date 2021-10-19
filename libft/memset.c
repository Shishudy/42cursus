#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	while (n != 0)
	{
		*p = (unsigned char) c;
		p++;
		n--;
	}
	return (s);
}

/*#include <stdio.h>
int	main()
{
	char	b[50] = "Hi my name is";
	int	c = '.';
	printf("%s ", ft_memset(b, c, 8*sizeof(char)));
	printf("%s\n", memset(b, c, 8*sizeof(char)));
}*/