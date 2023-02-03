/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:27:41 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/30 15:10:39 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>

int main(int argc, char **argv)
{
    int j;
    int n;
    char    c;
    
    if (argc != 3)
        return (write(1, "\n", 1));
    j = 0;
    while (argv[1][j])
    {
        c = argv[1][j];
        n = 0;
        while (n < j)
        {
            if (argv[1][j] == argv[1][n])
            {
                n = -1;
                break ;
            }
            n++;
        }
        if (n != -1)
            write(1, &c, 1);
        j++;
    }
    j = 0;
    while (argv[2][j])
    {
        c = argv[2][j];
        n = 0;
        while (argv[1][n])
        {
            if (argv[2][j] == argv[1][n])
            {
                n = -1;
                break ;
            }
            n++;
        }
        if (n != -1)
        {
            n = 0;
            while (n < j)
            {
                if (argv[2][j] == argv[2][n])
                {
                    n = -1;
                    break ;
                }
                n++;
            }
        }
        if (n != -1)
            write(1, &c, 1);
        j++;
    }
    return (write(1, "\n", 1));
}
