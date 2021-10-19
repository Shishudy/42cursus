#include<stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	while (s[size])
		size++;
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include<stdio.h>
#include <string.h>

int main ()
{
	char	*src;
	char	*dest;

	src = "teste";
	(void)dest;
	printf("Exemplo: %s\n", src);
	printf("%s\n", ft_strdup(src));
	printf("-------\n");
	printf("%s\n", strdup(src));
}*/