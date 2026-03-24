/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:17:09 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 12:54:30 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	refresh_display(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img);
	mlx_clear_window(win->mlx, win->win);
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->buf = mlx_get_data_addr(win->img, &(win->bits),
			&(win->bytes), &(win->end));
	plot_map(win, win->map);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void	pan_scroll(int key, t_window *win)
{
	if (key == LEFT)
		win->pan -= 10;
	else if (key == RIGHT)
		win->pan += 10;
	else if (key == UP)
		win->scroll -= 10;
	else if (key == DOWN)
		win->scroll += 10;
}

void	scale_zoom(int key, t_window *win)
{
	if (key == W)
		win->scale += 0.005;
	else if (key == S)
		win->scale -= 0.005;
	else if (key == Q)
		win->zoom -= 0.05;
	else if (key == E)
		win->zoom += 0.05;
}

void	rotate_tilt(int key, t_window *win)
{
	if (key == A)
		win->rotat -= 0.4;
	else if (key == D)
		win->rotat += 0.4;
	else if (key == Z)
		win->tiltx += 0.5;
	else if (key == X)
		win->tiltx -= 0.5;
	else if (key == F)
		win->tilty += 0.5;
	else if (key == G)
		win->tilty -= 0.5;
}

int	key_action(int key, t_window *win)
{
	if (key == ESC)
	{
		shut_down(win);
		return (0);
	}
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		pan_scroll(key, win);
	else if (key == W || key == S || key == Q || key == E)
		scale_zoom(key, win);
	else if (key == A || key == D || key == Z || key == X
		|| key == F || key == G)
		rotate_tilt(key, win);
	refresh_display(win);
	return (0);
}
