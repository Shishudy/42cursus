int	ft_atoi(char *nptr)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
			++nptr;
	if (*nptr == '-')
	{
		sign = -1;
	}
	if (*nptr == '+' || *nptr == '-')
		++nptr;
	while (*nptr != '\0')
	{
		if (*nptr < 48 || *nptr > 57)
			return (n * sign);
		n = n * 10 + *nptr - '0';
		++nptr;
	}
	return (n * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char *str;

	str = "+-123a";
	printf("%d ", atoi(str));
	printf("%d\n", ft_atoi(str));
}