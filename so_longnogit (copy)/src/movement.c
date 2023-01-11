/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/11 20:08:19 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


void	ground_to_image(t_vars *vars, t_object *image)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = image->x * SCALE;
	y = image->y * SCALE;
	while (++i < image->data.height)
	{
		j = -1;
		while (++j < image->data.width)
			my_mlx_pixel_put(&vars->img, (y + i), (x + j), my_mlx_pixel_get(&image->data, (i), (image->animation + j)));
	}
}

void	animation(t_vars *vars, int x, int y, int z)
{
	static int	change;

	change = change + z;
	if (change > 3)
		change = 0;
}

void	change_matrix(t_infomap *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height_y)
	{
		j = -1;
		while (++j < map->width_x)
		{
			if (map->grid[i][j]->id != '0')
			{
				map->grid[i][j]->animation += 8;
				if (map->grid[i][j]->animation > 64)
					map->grid[i][j]->animation = 0;
			}
		}
	}
}

void	collision(t_object *obj, t_object **map)
{
	int	x;
	int	y;

	x = obj->x / SCALE;
	y = obj->y / SCALE;
	if (map[x][y].id == '1')
	{
		obj->x -= (*on(S) - *on(W)) * 0.2;
		obj->y -= (*on(D) - *on(A)) * 0.2;
	}
}

int	key_up(int keycode, t_vars *vars)
{
	*on(keycode) = 0;
}

int	key_down(int keycode, t_vars *vars)
{
	*on(keycode) = 1;
	if (*on(ESC))
		end_game(vars);
}

void	movement(t_vars *vars, t_object *obj)
{
	// printf("%C, x: %f, y: %f\n", map()->grid[x][y]->id, obj->x, obj->y);
	if (map()->grid[(int)(obj->x + (*on(S) - *on(W)) * 0.2)][(int)(obj->y + (*on(D) - *on(A)) * 0.2)]->id != '1')
	{
		obj->x += (*on(S) - *on(W)) * 0.2;
		obj->y += (*on(D) - *on(A)) * 0.2;
	}
	// collision(obj, *map()->grid);
}
