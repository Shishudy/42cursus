int ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
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
		printf("%c ", ft_tolower(i));
		printf("%c\n", tolower(i));
		i++;
	}
}