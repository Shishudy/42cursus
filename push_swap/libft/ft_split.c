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

void	ft_split(char const *s, char c)
{
	int		k;
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc(sizeof(*split) * (ft_count(s, c) + 1));
	if (split == NULL)
		return (NULL);
	k = 0;
	split = ft_splitter(s, c, k, split);
	while (split[k])
		ft_lstnew(ft_atoi(split[k++]));
}
