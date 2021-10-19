int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <string.h>
#include <stdio.h>

int	main()
{
	char *s1= "Eu sou aluno da 42";
	char *s2= "Eu sou aluno da UA";
	printf("%d ", ft_strncmp(s1, s2, 18));
	printf("%d\n", strncmp(s1, s2, 18));
}