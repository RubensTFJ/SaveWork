/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/02 20:58:15 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


void	put_ground(t_vars *vars, t_object *image, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	x *= SCALE;
	y *= SCALE;
	while (++i < image->data.height)
	{
		j = -1;
		while (++j < image->data.width)
			my_mlx_pixel_put(&vars->img, (y + i), (x + j), my_mlx_pixel_get(&image->data, (0 + i), (0 + j)));
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
	t_list	*object;

	// player()->y += (*on(S) - *on(W));
	// player()->x += (*on(D) - *on(A));
	animation(vars, 0 * 32, 2 * 48, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
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