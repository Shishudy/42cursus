int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

#include <ctype.h>
#include <stdio.h>

int	main()
{
	int	i;

	i = 0;
	while (i != 257)
	{
		printf("%d", isprint(i));
		printf("%d\n", ft_isprint(i));
		i++;
	}
}