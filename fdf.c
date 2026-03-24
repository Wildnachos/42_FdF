/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:46:52 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 10:47:46 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_plot	init_plot(int x, int y, int z, t_window *win)
{
	t_plot	res;
	double	rad;
	double	rad2;
	double	rad3;

	rad = win->rotat * M_PI / 180;
	rad2 = win->tiltx * M_PI / 180;
	rad3 = win->tilty * M_PI / 180;
	res.x = x;
	res.y = y;
	res.z = z;
	res.nx = (x * cos(rad) - y * sin(rad)) * cos(rad3)
		- (z * win->scale * sin(rad3));
	res.ny = (y * cos(rad) + x * sin(rad)) * cos(rad2)
		- (z * win->scale * sin(rad2));
	return (res);
}

t_line	get_coords(t_window *win, t_map *map, t_plot p1, t_plot p2)
{
	double		height;
	double		width;
	double		step;
	t_coords	coord;

	height = (win->height * win->zoom) / map->max_x;
	width = win->width * win->zoom / map->max_y;
	if (height > width)
		step = width;
	else
		step = height;
	coord.bx = (win->width / 2) - (step * map->max_x / 3.5)
		+ (p1.nx * step) + win->pan;
	coord.ex = (win->width / 2) - (step * map->max_x / 3.5)
		+ (p2.nx * step) + win->pan;
	coord.by = (win->height / 2) - (step * map->max_y / 1.5)
		+ (p1.ny * step) + win->scroll;
	coord.ey = (win->height / 2) - (step * map->max_y / 1.5)
		+ (p2.ny * step) + win->scroll;
	return (init_line(coord.bx, coord.ex, coord.by, coord.ey));
}

void	plot_map(t_window *win, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			if (x < map->max_x - 1)
				draw_line(win, get_coords(win, map,
						init_plot(x, y, ft_atoi(map->map[y][x]), win),
						init_plot(x + 1, y, ft_atoi(map->map[y][x + 1]), win)),
					get_colour(map->map[y][x]), get_colour(map->map[y][x + 1]));
			if (y < map->max_y - 1)
				draw_line(win, get_coords(win, map,
						init_plot(x, y, ft_atoi(map->map[y][x]), win),
						init_plot(x, y + 1, ft_atoi(map->map[y + 1][x]), win)),
					get_colour(map->map[y][x]), get_colour(map->map[y + 1][x]));
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_window	*win;
	t_map		*map;

	if (argc != 2)
		return (0);
	map = parse_map(argv[1]);
	if (!map || !map->map)
		return (0);
	win = init_win(1000, 1000, "fdf");
	if (!win)
		return (0);
	win->map = map;
	win->rotat = 30;
	win->pan = 0;
	win->scroll = 0;
	win->scale = 0.15;
	win->zoom = 0.8;
	win->tiltx = 40;
	win->tilty = 0;
	plot_map(win, win->map);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_hook(win->win, 2, 1L << 0, key_action, win);
	mlx_hook(win->win, 17, 0, shut_down, win);
	mlx_loop(win->mlx);
	return (0);
}
