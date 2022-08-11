/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 08:27:57 by vjean             #+#    #+#             */
/*   Updated: 2022/08/11 11:52:35 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_str_chr(const char *s1, int c)
{
	int	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == (char) c)
			return ((char *)&s1[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}

char	*returned_line(char *s)
{
	int		i;
	char	*newline;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (!newline)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		newline[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		newline[i] = s[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*keep_the_rest(char *str)
{
	int		i;
	int		j;
	char	*newstash;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	newstash = ft_calloc_gnl(sizeof(char), (strlen_gnl(str) - i) + 1);
	if (!newstash)
		return (NULL);
	j = 0;
	while (str && str[i + j])
	{	
		newstash[j] = str[i + j];
		j++;
	}
	free(str);
	return (newstash);
}

char	*ft_copy_n_join(char *stash, char *buffer)
{
	char	*temp;

	if (!stash)
		return (gnl_strdup(buffer));
	else
		temp = gnl_strjoin(stash, buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	int			ret;
	char		*buffer;
	char		*res;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = ft_calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
	while (ret != 0 && !gnl_str_chr(stash[fd], '\n'))
	{
		 ret = do_shit(ret, buffer, stash, fd);
		 if (ret == -1)
		 	return (NULL);
	}
	free(buffer);
	if (strlen_gnl(stash[fd]) == 0)
	{
		free(stash[fd]);
		return (NULL);
	}
	res = returned_line(stash[fd]);
	stash[fd] = keep_the_rest(stash[fd]);
	return (res);
}
