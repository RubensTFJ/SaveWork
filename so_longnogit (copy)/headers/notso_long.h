/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:41:51 by rteles-f          #+#    #+#             */
/*   Updated: 2022/12/29 22:02:38 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "ft_printf.h"
# include <mlx.h>
# include <sys/wait.h>
# include <sys/time.h>

# define ESC	65307
# define S		115
# define D      100
# define W      119
# define A      97
# define SPACE	32
# define SCALE	64

typedef struct s_sprite {
	void	*tile;
	void	*wall;
}	t_sprite;


typedef struct s_player {
	double	x;
	double	y;
}	t_player;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	int		key;
}	t_vars;

typedef struct s_position {
	double	x;
	double	y;
}	t_position;

//////////////////////////////
typedef struct s_list t_list;

struct s_list {
	int		marker;
	t_data	*the;
	t_list	*next;
};
//////////////////////////////

// typedef void	(*exe)(int, int, t_vars *);
typedef void	(*exe)(t_vars *vars);

typedef struct map_struct {
	char	**map;
	int		width_x;
	int		height_y;
	int		exit[2];
	int		pstart[2];
	int		collectables[2];
}	t_infomap;

t_infomap	*map(void);
t_infomap	*init_mapstruct(t_infomap *map);
char		*get_next_line(int fd);
int			check_map(char *file, t_infomap *vmap);
int			check_name(char *name);
int			fill_map(t_infomap *vmap, char *line, int fd, int pos);
int			check_square(t_infomap *vmap);
int			check_border(t_infomap *vmap);
int			check_characters(t_infomap *vmap);
int			characters_errors(t_infomap *vmap);
int			is_valid_character(t_infomap *vmap, char c, int i, int j);
void		check_reach(t_infomap *info, int i, int j);
int			check_reached(t_infomap *vmap);
int			is_in_str(char c, char *string);
void		free_map(t_infomap *map);
int			bl_strlen(char *string);
int			ft_strlen(char *str);
void		*ft_calloc(size_t n, size_t xsize);
char		**copy_map(t_infomap *vmap);
void		run_game(void);
t_position	*position(void);

int			my_mlx_pixel_get(t_data *data, int x, int y);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

t_data		*sprite(void);
char		*on(int press);
t_player 	*player(void);

void		puttex(t_vars *vars, int x, int y);
void		put_ground(t_vars *vars, t_data *image, int x, int y);

void 		movement(t_vars *vars);
int			key_down(int keycode, t_vars *vars);
int 		key_up(int keycode, t_vars *vars);
int			end_game(t_vars *vars);

void		my_mlx_pixel_clear(t_data *data, int x, int y, int color);

t_data		*blank(void);

t_list		**img_list(void);

void		create_image(char *path, t_vars *vars);

void		put_wall(t_vars *vars, t_data *image, int x, int y);


#endif