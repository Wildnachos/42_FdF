/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:58:10 by akabbaj           #+#    #+#             */
/*   Updated: 2025/02/20 12:58:10 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define A 97
# define D 100
# define W 119
# define S 115
# define Q 113
# define E 101
# define Z 122
# define X 120
# define F 102
# define G 103

typedef struct s_map
{
	char	***map;
	int		max_x;
	int		max_y;
}	t_map;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bits;
	int		bytes;
	int		end;
	char	*buf;
	int		height;
	int		width;
	double	scale;
	double	rotat;
	double	scroll;
	double	pan;
	double	zoom;
	double	tiltx;
	double	tilty;
	t_map	*map;
}	t_window;

typedef struct s_line
{
	double	start_x;
	double	end_x;
	double	start_y;
	double	end_y;
	double	dif_x;
	double	dif_y;
}	t_line;

typedef struct s_plot
{
	int		x;
	int		y;
	int		z;
	double	nx;
	double	ny;
}	t_plot;

typedef struct s_coords
{
	double	bx;
	double	ex;
	double	by;
	double	ey;
}	t_coords;

typedef struct s_colours
{
	int		sr;
	int		sg;
	int		sb;
	int		er;
	int		eg;
	int		eb;
	double	stepr;
	double	stepg;
	double	stepb;
	int		colour;
}	t_colours;

t_map		*parse_map(char *fname);
void		plot_map(t_window *win, t_map *map);
void		draw_line(t_window *info, t_line line, int startc, int endc);
t_window	*init_win(int y, int x, char *name);
t_line		init_line(int bx, int ex, int by, int ey);
int			key_action(int key, t_window	*win);
int			shut_down(t_window *win);
int			free_map(t_window *win);
void		free_line(char **line);
int			free_justmap(char ***map);
char		**ft_split(char *s, char *set);
int			ft_atoi(const char *nptr);
int			wspace(char c);
int			get_colour(char *point);
int			in(char c, char *set);
int			ft_hexatoi(const char *nptr);
t_colours	*init_colours(int val1, int val2, double step);
void		incr_colour(t_colours *colour, int count, double step);

#endif
