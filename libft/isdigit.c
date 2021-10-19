int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
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
		printf("%d", isdigit(i));
		printf("%d\n", ft_isdigit(i));
		i++;
	}
}