/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:50:46 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 13:59:45 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_colour(char *point)
{
	int		colour;
	int		count;

	if (!in(',', point))
		return (16777215);
	count = 0;
	while (point[count] != ',')
		count++;
	colour = ft_hexatoi(point + count);
	return (colour);
}

t_colours	*init_colours(int val1, int val2, double step)
{
	t_colours	*res;

	res = malloc(sizeof(t_colours));
	if (!res)
		return (0);
	res->sr = (val1 >> 16) & 0xFF;
	res->sg = (val1 >> 8) & 0xFF;
	res->sb = val1 & 0xFF;
	res->er = (val2 >> 16) & 0xFF;
	res->eg = (val2 >> 8) & 0xFF;
	res->eb = val2 & 0xFF;
	res->stepr = (res->er - res->sr) / step;
	res->stepg = (res->eg - res->sg) / step;
	res->stepb = (res->eb - res->sb) / step;
	res->colour = res->sr << 16 | res->sg << 8 | res->sb;
	return (res);
}

void	incr_colour(t_colours *colour, int count, double step)
{
	colour->sr += colour->stepr;
	colour->sg += colour->stepg;
	colour->sb += colour->stepb;
	if (colour->sr > 255)
		colour->sr = 255;
	else if (colour->sr < 0)
		colour->sr = 0;
	if (colour->sg > 255)
		colour->sg = 255;
	else if (colour->sg < 0)
		colour->sg = 0;
	if (colour->sb > 255)
		colour->sb = 255;
	else if (colour->sb < 0)
		colour->sb = 0;
	colour->colour = colour->sr << 16 | colour->sg << 8 | colour->sb;
	if (count >= step)
		free(colour);
}
