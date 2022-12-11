/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:35:07 by rasantos          #+#    #+#             */
/*   Updated: 2022/05/23 16:35:09 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_remainder(int fd, char *remainder);
char	*ft_new_line(char *remainder);
char	*ft_new_remainder(char *remainder);
size_t	ft_strlen( char *s);
char	*ft_strchr( char *s, int c);
char	*ft_strjoin(char *remainder, char *buf);

#endif
