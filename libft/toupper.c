int ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

#include <stdio.h>
#include <ctype.h>

int	main()
{
	int	i;

	i = 0;
	while (i != 257)
	{
		printf("%c ", ft_toupper(i));
		printf("%c\n", toupper(i));
		i++;
	}
}