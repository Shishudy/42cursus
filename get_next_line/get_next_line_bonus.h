/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:55:11 by rasantos          #+#    #+#             */
/*   Updated: 2022/11/18 18:03:58 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
