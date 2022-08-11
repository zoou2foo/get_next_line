/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 08:21:18 by vjean             #+#    #+#             */
/*   Updated: 2022/08/11 11:45:26 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*gnl_str_chr(const char *s1, int c);
size_t	strlen_gnl(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(char *s1);
int		do_shit(int ret, char *buffer, char **stash, int fd);
char	*ft_copy_n_join(char *stash, char *buffer);

#endif