unsigned long int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char *str;

	str = "fds";
	printf("%lu ", strlen(str));
	printf("%lu\n", ft_strlen(str));
}