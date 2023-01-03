/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:13:24 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/02 21:29:02 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <ft_printf.h>
# include <mlx.h>
# include <sys/time.h>

# define ESC	65307
# define S		115
# define D      100
# define W      119
# define A      97
# define SPACE	32
# define SCALE	64

typedef struct s_list t_list;
typedef struct s_object t_object;
typedef struct s_vars t_vars;
typedef void	*(exe)(t_vars *vars, t_object *obj);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

struct	s_vars {
	void	*mlx;
	void	*win;
	int		key;
	t_data	img;
};

struct s_object {
	int		id;
	double	x;
	double	y;
	void	*(*new_pos)(t_vars *vars, t_object *obj);
	exe		*trail;
	t_data	data;
	int		animation;
};

struct s_list {
	t_object	obj;
	t_list		*next;
};

typedef struct map_struct {
	char		**map;
	t_object	***grid;
	int			width_x;
	int			height_y;
	int			exit[2];
	int			pstart[2];
	int			collectables[2];
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

int			my_mlx_pixel_get(t_data *data, int x, int y);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

t_data		*sprite(void);
char		*on(int press);

void		puttex(t_vars *vars, t_data *image, int x, int y);
void		put_ground(t_vars *vars, t_object *image, int x, int y);

void 		movement(t_vars *vars);
int			key_down(int keycode, t_vars *vars);
int 		key_up(int keycode, t_vars *vars);
int			end_game(t_vars *vars);

void		my_mlx_pixel_clear(t_data *data, int x, int y, int color);

t_data		*blank(void);

t_list		**obj_list(void);

t_object	*create_object(char *path, t_vars *vars, int id);

void		do_nothing(t_vars *vars);

void		set_new_object(t_object *obj);

void		make_frame(t_vars *vars, t_infomap *map);

#endif