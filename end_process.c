/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:38:45 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/18 11:38:45 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_map(t_window *win)
{
	int	ycount;
	int	xcount;

	ycount = 0;
	if (!win->map)
		return (0);
	if (!win->map->map)
		return (0);
	while (ycount < win->map->max_y)
	{
		xcount = 0;
		while (win->map->map[ycount][xcount])
			free(win->map->map[ycount][xcount++]);
		if (win->map->map[ycount])
			free(win->map->map[ycount]);
		ycount++;
	}
	free(win->map->map);
	free(win->map);
	return (0);
}

int	free_justmap(char ***map)
{
	int	ycount;
	int	xcount;

	ycount = 0;
	if (!map)
		return (0);
	while (map[ycount])
	{
		xcount = 0;
		while (map[ycount][xcount])
			free(map[ycount][xcount++]);
		if (map[ycount])
			free(map[ycount]);
		ycount++;
	}
	free(map);
	return (0);
}

void	free_line(char **line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

int	shut_down(t_window *win)
{
	mlx_loop_end(win->mlx);
	if (win->img)
		mlx_destroy_image(win->mlx, win->img);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		mlx_destroy_display(win->mlx);
	if (win->mlx)
		free(win->mlx);
	free_map(win);
	free(win);
	exit(EXIT_SUCCESS);
	return (0);
}
