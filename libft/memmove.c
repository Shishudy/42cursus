#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned const char *s;
	size_t	i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (s < d)
	{
		while (i != n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n != 0 )
		{
			d[i] = s[i];
			i++;
			n--;
		}
	}
	return (dest);
}

/*#include <stdio.h>
int	main()
{
	char	b[50] = "Hi my name is";
	char	c[50] = "Yo";
	printf("%s---", ft_memmove(b, c, 8*sizeof(char)));
	printf("%s\n", memmove(b, c, 8*sizeof(char)));
}*/