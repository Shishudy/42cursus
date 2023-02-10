// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut" | cat -e
// la lumiere soit et la lumiere fut Que$
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y" | cat -e
// zLKIJz , 23y AkjhZ$
// $>
// $>./rostring "first" "2" "11000000" | cat -e
// first$
// $>
// $>./rostring | cat -e
// $
// $>

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	space;
	char	c;
	char	*str;

	if (argc < 2)
		return (write(1, "\n", 1));
	str = argv[1];
	while ((*str == 32 || *str == 9) && *str)
		str++;
	i = 0;
	while ((str[i] != 32 && str[i] != 9) && str[i])
		i++;
	while ((str[i] == 32 || str[i] == 9) && str[i])
		i++;
	while (str[i])
	{
		space = 0;
		while (str[i] == 32 || str[i] == 9)
		{
			space = 1;
			i++;
		}
		if (space == 1)
		{
			c = ' ';
			write(1, &c, 1);
		}
		else
		{
			c = str[i];
			write(1, &c, 1);
			i++;
		}
	}
	if (space == 0)
	{
		c = ' ';
		write(1, &c, 1);
	}	
	i = 0;
	while ((str[i] != 32 && str[i] != 9) && str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
	return (write(1, "\n", 1));
}