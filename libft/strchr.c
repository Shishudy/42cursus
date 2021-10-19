char	*ft_strchr(char *big, int little)
{
	int	i;

	i = 0;
	while (big[i] != '\0')
	{
		if (big[i] == little)
			return (&big[i]);
		i++;
	}
	return (0);
}

#include <string.h>
#include <stdio.h>

int	main()
{
	char *big = "Eu sou aluno da 42";
	int little = 'a';
	printf("%s ", ft_strchr(big, little));
	printf("%s\n", strchr(big, little));
}