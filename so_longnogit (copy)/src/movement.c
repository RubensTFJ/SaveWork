/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/09 21:26:00 by rteles-f         ###   ########.fr       */
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
// 
// void	puttex(t_vars *vars, t_data *image, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < 48)
// 	{
// 		j = -1;
// 		while (++j < 32)
// 			my_mlx_pixel_put(&vars->img, (player()->x - 16 + j), (player()->y \
// 			- 24 + i), my_mlx_pixel_get(image, (x + j), (y + i)));
// 	}
// }

// void	puttex(t_vars *vars, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < 48)
// 	{
// 		j = -1;
// 		while (++j < 32)
// 			my_mlx_pixel_put(&vars->img, (player()->x - 16 + j), (player()->y \
// 			- 24 + i), my_mlx_pixel_get(sprite(), (x + j), (y + i)));
// 	}
// }

void	animation(t_vars *vars, int x, int y, int z)
{
	static int	change;

	change = change + z;
	if (change > 3)
		change = 0;
	// puttex(vars, (x + (change * 32)), 3);
}

// void	clear_trail(t_vars *vars)
// {
// 	int	i;
// 	int	j;
	
// 	i = -1;
// 	while (++i < 48)
// 	{
// 		j = -1;
// 		while (++j < 32)
// 			my_mlx_pixel_clear(&vars->img, (player()->x  - 16 + j), (player()->y  \
// 			- 24 + i), 0x00000000);
// 	}
// }

int	key_up(int keycode, t_vars *vars)
{
	*on(keycode) = 0;
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
	printf("animation: %i\n", map->grid[0][0]->animation);
}

int	key_down(int keycode, t_vars *vars)
{
	*on(keycode) = 1;
	if (*on(ESC))
		end_game(vars);
	if (*on(SPACE))
	{
		make_frame(vars, map());
		change_matrix(map());
		make_frame(vars, map());
		// make_frame(&vars, map());
	}
		// animation(vars, 0 * 32, 2 * 48, 1);
		// puttex(vars, 4 * 32, 3 * 48);
}

void	movement(t_vars *vars, t_object *obj)
{
	obj->x += (*on(S) - *on(W));
	obj->y += (*on(D) - *on(A));
	// if (obj->x > map()->height_y)
	// 	obj->x = map()->height_y - 1;
	// if (obj->y > map()->width_x)
	// 	obj->y = map()->width_x - 1;
	// if (obj->y < 0)
	// 	obj->y = 1;
	// if (obj->x < 0)
	// 	obj->x = 1;
	// map()->grid[(int)(obj->x)][(int)(obj->y)]->on_top = obj;
	// map()->grid[(int)(obj->x + 1)][(int)(obj->y)]->on_top = obj;
	// map()->grid[(int)(obj->x)][(int)(obj->y + 1)]->on_top = obj;
	// map()->grid[(int)(obj->x + 1)][(int)(obj->y + 1)]->on_top = obj;
}

	// my_mlx_pixel_put(&vars->img, player()->x, player()->y, 0x00FF0000);
	// puttex(vars, 0 * 32, 2 * 48);

// void	movement(t_vars *vars)
// {
// 	player()->y += (*on(S) - *on(W));
// 	player()->x += (*on(D) - *on(A));
// 	my_mlx_pixel_put(&vars->img, player()->x, player()->y, 0x00FF0000);
// 	puttex(vars, 1 * 63, 0 * 63);
// 	write(1, "put\n", 4);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// 	write(1, "print\n", 6);
// 	clear_trail(vars);
// 	write(1, "remove\n", 7);
// }