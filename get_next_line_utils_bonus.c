/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:43:31 by vjean             #+#    #+#             */
/*   Updated: 2022/08/11 11:50:54 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	do_shit(int ret, char *buffer, char **stash, int fd)
{
	//buffer = ft_calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
	/*while (ret != 0 && !gnl_str_chr(stash[fd], '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free (buffer);
			//return (NULL);
			return ;
		}
		buffer[ret] = '\0';
		if (ret > 0)
			stash[fd] = ft_copy_n_join(stash[fd], buffer);
	}
	free(buffer);*/
	ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free (buffer);
			return (-1);
		}
		buffer[ret] = '\0';
		if (ret > 0)
			stash[fd] = ft_copy_n_join(stash[fd], buffer);
	return (ret);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{		
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*newline;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	if (!s2)
		return (gnl_strdup(s1));
	newline = malloc((strlen_gnl(s1) + strlen_gnl(s2) + 1) * (sizeof(char)));
	if (!newline)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		newline[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		newline[j++] = s2[i++];
	free (s1);
	newline[j] = '\0';
	return (newline);
}

char	*gnl_strdup(char *s1)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((strlen_gnl(s1) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
