#include "libft.h"

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;
	int	i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (n != 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}

/*#include <stdio.h>
int	main()
{
	char	b[50] = "Hi my name is";
	char	c[50] = "Yo";
	printf("%s---", ft_memcpy(b, c, 8*sizeof(char)));
	printf("%s\n", memcpy(b, c, 8*sizeof(char)));
}*/