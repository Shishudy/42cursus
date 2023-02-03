// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int len;
    int *array;
    int i;

    i = 0;
    printf("%i, ", end);
    printf("%i\n", start);
    if (end > start)
    {
        len = end - start;
        array = malloc(sizeof(int) * (len + 2));
        if (!array)
            return (NULL);
        while (end >= start)
            array[i++] = end--;
    }
    else if (end < start)
    {
        len = start - end;
        array = malloc(sizeof(int) * (len + 2));
        if (!array)
            return (NULL);
        while (end <= start)
            array[i++] = end++;
    }
    else if (end == start)
    {
        array = malloc(sizeof(int) * 1);
        array[i] = end;
    }
    return (array);
}

int	main(void)
{
	int start = 20;
	int	end = -40;
	int length;
	int *new_str;

	new_str = ft_rrange(start, end);
	length = 0;
	while (length < 55)
		printf("%i, ", new_str[length++]);
    free(new_str);
	return (0);
}