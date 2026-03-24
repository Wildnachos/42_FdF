/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:53:42 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 13:53:42 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*init_win(int y, int x, char *name)
{
	t_window	*res;

	res = malloc(sizeof(t_window));
	if (!res)
		return (0);
	res->height = y;
	res->width = x;
	res->scale = 0;
	res->rotat = 0;
	res->pan = 0;
	res->mlx = mlx_init();
	res->win = mlx_new_window(res->mlx, x, y, name);
	res->img = mlx_new_image(res->mlx, x, y);
	res->buf = mlx_get_data_addr(res->img, &(res->bits),
			&(res->bytes), &(res->end));
	return (res);
}

t_line	init_line(int bx, int ex, int by, int ey)
{
	t_line	res;

	res.start_x = bx;
	res.end_x = ex;
	res.start_y = by;
	res.end_y = ey;
	res.dif_x = ex - bx;
	res.dif_y = ey - by;
	return (res);
}

void	put_pixels(t_window *info, int x, int y, int colour)
{
	char	*dst;

	dst = info->buf + (y * info->bytes + x * (info->bits / 8));
	*(unsigned int *) dst = colour;
}

void	draw_line(t_window *info, t_line line, int startc, int endc)
{
	double		inc_x;
	double		inc_y;
	double		step;
	t_colours	*colours;
	int			count;

	if (fabs(line.dif_x) > fabs(line.dif_y))
		step = fabs(line.dif_x);
	else
		step = fabs(line.dif_y);
	inc_x = line.dif_x / step;
	inc_y = line.dif_y / step;
	count = 0;
	colours = init_colours(startc, endc, step);
	if (!colours)
		return ;
	while (count++ < step)
	{
		if (line.start_x < info->width && line.start_y < info->height
			&& line.start_x > 0 && line.start_y > 0)
			put_pixels(info, line.start_x, line.start_y, colours->colour);
		incr_colour(colours, count, step);
		line.start_x += inc_x;
		line.start_y += inc_y;
	}
}
