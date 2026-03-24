/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:50:01 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 09:50:41 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gen_line(char ****map, char **line, int count)
{
	char	***res;
	int		y;

	y = 0;
	res = malloc(sizeof(char **) * (count + 2));
	if (!res)
	{
		free_justmap((*map));
		free_line(line);
		return ;
	}
	while (y < count)
	{
		res[y] = (*map)[y];
		y++;
	}
	res[y++] = line;
	res[y] = 0;
	free((*map));
	*map = res;
}

char	***read_map(int fd)
{
	char	*line;
	char	**line_split;
	char	***map;
	int		count;

	map = 0;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, " \n\t");
		free(line);
		gen_line(&map, line_split, count++);
		if (!map)
			return (0);
		line = get_next_line(fd);
	}
	gen_line(&map, 0, count);
	return (map);
}

void	get_xy(t_map *map_info)
{
	int	xcount;
	int	ycount;
	int	xcount2;

	ycount = 0;
	xcount = 0;
	while (map_info->map[ycount][xcount])
		xcount++;
	while (map_info->map[ycount])
	{
		xcount2 = 0;
		while (map_info->map[ycount][xcount2])
			xcount2++;
		if (xcount2 != xcount)
		{
			map_info->max_x = -1;
			return ;
		}
		ycount++;
	}
	map_info->max_x = xcount;
	map_info->max_y = ycount;
	return ;
}

t_map	*parse_map(char *fname)
{
	char	***map;
	t_map	*map_info;
	int		fd;

	map_info = malloc(sizeof(t_map));
	fd = open(fname, O_RDONLY);
	if (fd == -1 || !map_info)
	{
		if (map_info)
			free(map_info);
		return (0);
	}
	map = read_map(fd);
	close(fd);
	if (!map)
		return (0);
	map_info->map = map;
	get_xy(map_info);
	if (map_info->max_x == -1)
	{
		free_justmap(map_info->map);
		free(map_info);
		return (0);
	}
	return (map_info);
}
