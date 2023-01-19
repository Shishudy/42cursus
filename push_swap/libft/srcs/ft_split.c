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

/*static int	ft_count(char const *s, char c)
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
}*/

static int	str_words(char const *str, char sep)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != sep && str[i])
			i++;
		result++;
	}
	return (result);
}

static	char	*get_next_word(const char *str, int *i, char sep)
{
	int		j;
	char	*new;

	while (str[*i] == sep)
		if (str[(*i)++] == '\0')
			return (NULL);
	j = 0;
	while (str[*i + j] != sep && str[*i + j])
		j++;
	if (j != 0)
	{
		new = (char *)malloc(sizeof(char) * (j + 1));
		if (new == NULL)
			return (NULL);
		j = 0;
		while (str[*i] != sep && str[*i])
			new[j++] = str[(*i)++];
		new[j] = '\0';
	}
	else
		return (NULL);
	return (new);
}

char	**ft_split(char const *str, char sep)
{
	char	**list;
	char	*word;
	int		*i;
	int		j;
	int		k;

	list = (char **)malloc(sizeof(char *) * (str_words(str, sep) + 1));
	if (list == NULL)
		return (NULL);
	j = 0;
	i = &j;
	k = 0;
	while (k < str_words(str, sep))
	{
		word = get_next_word(str, i, sep);
		if (word == NULL)
			break ;
		list[k++] = word;
	}
	list[k] = NULL;
	return (list);
}