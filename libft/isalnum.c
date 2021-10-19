int	ft_isalnum(int c)
{
	if ((c < 65 || c > 90) && (c < 97 || c > 122) && (c < 48 || c > 57))
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
		printf("%d", isalnum(i));
		printf("%d\n", ft_isalnum(i));
		i++;
	}
}