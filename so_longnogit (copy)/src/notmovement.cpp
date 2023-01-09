/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:17:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/03 19:41:36 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


void	put_ground(t_vars *vars, t_data *image, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
			my_mlx_pixel_put(&vars->img, (x + j), (y + i), my_mlx_pixel_get(image, (0 + j), (0 + i)));
	}
}

void	put_wall(t_vars *vars, t_data *image, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
			my_mlx_pixel_put(&vars->img, (x + j), (y + i), my_mlx_pixel_get(image, (0 + j), (1 * SCALE + i)));
	}
}

void	puttex(t_vars *vars, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 48)
	{
		j = -1;
		while (++j < 32)
		{
			mlx_pixel_put(vars->mlx, vars->win, (int)(player()->x - 16 + j), (int)(player()->y \
			- 24 + i), my_mlx_pixel_get(sprite(), (x + j), (y + i)));
		}
	}
}

// mlx_pixel_put(vars->mlx, vars->win, (int)(player()->x - 16 + j), (int)(player()->y \
// 			- 24 + i), my_mlx_pixel_get(sprite(), (x + j), (y + i)));

void	animation(t_vars *vars, int x, int y, int z)
{
	static int	change;

	change = change + z;
	if (change > 3)
		change = 0;
	// puttex(vars, (x + (change * 32)), ((*on(A) * 48) + (*on(W) * 144) + (*on(D) * 96) - (*on(S))));
	// puttex(vars, (x + (change * 32)), 1);
	puttex(vars, (x + (change * 32)), 3);

}

void	clear_trail(t_vars *vars)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < 48)
	{
		j = -1;
		while (++j < 32)
			my_mlx_pixel_clear(&vars->img, (player()->x  - 16 + j), (player()->y  \
			- 24 + i), 0x00000000);
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
	if (*on(SPACE))
		animation(vars, 0 * 32, 2 * 48, 1);
		// puttex(vars, 4 * 32, 3 * 48);
}

void	movement(t_vars *vars)
{	
	// clear_trail(vars);
	player()->y += (*on(S) - *on(W));
	player()->x += (*on(D) - *on(A));
	// my_mlx_pixel_put(&vars->img, player()->x, player()->y, 0x00FF0000);
	// puttex(vars, 0 * 32, 0 * 48);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	animation(vars, 0 * 32, 2 * 48, 0);
}

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
