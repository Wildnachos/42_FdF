/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:17:44 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/17 15:19:43 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buf(char *buffer, int fd)
{
	char	*res;
	int		reading;

	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer)
			return (0);
	}
	reading = 1;
	while (!in_str(buffer, '\n') && reading != 0)
	{
		res = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!res)
			return (free_return(res));
		reading = read(fd, res, BUFFER_SIZE);
		if (reading < 0 || (reading == 0 && !buffer[0]))
		{
			free(res);
			return (free_return(buffer));
		}
		buffer = concat(buffer, res);
		free (res);
	}
	return (buffer);
}

char	*gen_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	j = 0;
	while (j < i)
	{
		res[j] = buffer[j];
		j++;
	}
	res[j] = 0;
	return (res);
}

static char	*gen_new_buffer(char *buffer)
{
	int		i;
	int		len;
	char	*newbuf;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	len = 0;
	while (buffer[i + len])
		len++;
	newbuf = malloc(sizeof(char) * (len + 1));
	if (!newbuf)
		return (0);
	len = 0;
	while (buffer[i])
		newbuf[len++] = buffer[i++];
	newbuf[len] = '\0';
	free(buffer);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = fill_buf(buffer, fd);
	if (!buffer)
		return (0);
	next_line = gen_next_line(buffer);
	if (!next_line)
	{
		free(buffer);
		return (0);
	}
	buffer = gen_new_buffer(buffer);
	return (next_line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main()
// {
// 	int	i;

// 	i = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(i));
// 	printf("%s", get_next_line(i));
// 	printf("%s", get_next_line(i));
// 	//printf("%s", get_next_line(i));
// }
