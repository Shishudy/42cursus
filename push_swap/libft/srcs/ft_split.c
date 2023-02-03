/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:33:52 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/08 16:33:53 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	char	last;
	int		i;
	int		j;

	last = c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (last == c && s[i] != c)
			j++;
		last = s[i];
		i++;
	}
	return (j);
}

static	int	ft_countchar(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i])
	{
		if (s[i + 1] == c || s[i + 1] == '\0')
			return (j);
		i++;
		j++;
	}
	return (j);
}

static char	**ft_splitter(char const *s, char c, int k, char **split)
{
	char	*ss;
	int		j;
	int		i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		ss = (char *)malloc(sizeof(char) * (ft_countchar(s, c, i) + 2));
		if (ss == NULL)
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			ss[j++] = s[i++];
		ss[j] = '\0';
		split[k++] = ss;
	}
	split[k] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc((ft_count(s, c) + 1) * sizeof(*split));
	if (split == NULL)
		return (NULL);
	k = 0;
	split = ft_splitter(s, c, k, split);
	return (split);
}

/*static char	**split(char **strarray, char *str, char c, int counter_strs)
{
	int		i;
	char	*newstr;

	newstr = NULL;
	i = 0;
	while (*str == c)
		str++;
	while (str[i] != c && str[i])
		i++;
	if (i > 0)
		newstr = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str != c && *str && newstr)
		newstr[i++] = *str++;
	if (newstr)
		newstr[i] = '\0';
	if (newstr)
		strarray = split(strarray, str, c, counter_strs + 1);
	else
		strarray = malloc(sizeof(char *) * (counter_strs + 1));
	strarray[counter_strs] = newstr;
	free (newstr);
	return (strarray);
}

char	**ft_split(const char *str, char c)
{
	return (split(0, (char *)str, c, 0));
}*/
