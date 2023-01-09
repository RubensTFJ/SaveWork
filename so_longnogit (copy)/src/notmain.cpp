/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:00:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/03 19:42:12 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	end_game(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, sprite()->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(map());
	exit(0);
	return (0);
}

exe	*define_move(void)
{
	exe	*function;

	return (function);
}

int	update(t_vars *vars)
{
	movement(vars);
	(void *)vars;
	return (0);
}

t_data	*blank(void)
{
	static t_data	blank;
	
	return (&blank);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterate;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		iterate = *lst;
		while (iterate->next != NULL)
			iterate = iterate->next;
		iterate->next = new;
	}
}

void	init_images(t_vars *vars)
{
	create_image("sprites/ground.xpm", vars);
}

void	create_image(char *path, t_vars *vars)
{
	t_list	*node;
	t_data	*image;

	node = calloc(sizeof(t_list), 1);
	image = calloc(sizeof(t_data), 1);
	node->the = image;
	node->the->img = mlx_xpm_file_to_image(vars->mlx, path, &node->the->width, &node->the->height);
	node->the->addr = mlx_get_data_addr(node->the->img, &node->the->bits_per_pixel, &node->the->line_length, &node->the->endian);
	ft_lstadd_back(img_list(), node);
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_down, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_up, vars);
	mlx_loop_hook(vars->mlx, update, vars);
}

void	test_canvas(t_vars *vars, t_list *image, int xl, int yl)
{
	int	i;
	int	j;


	// put_ground(vars, image->the, (0 * SCALE), (0 * SCALE));
	// put_wall(vars, image->the, (1 * SCALE), (0 * SCALE));
	i = -1;
	while (++i < xl)
	{
		j = -1;
		while (++j < yl)
		{
			if (map()->map[i][j] == '1' || map()->map[i][j] == '/')
				put_ground(vars, image->the, (j * SCALE), (i * SCALE));
				// put_wall(vars, image->the, (j * SCALE), (i * SCALE));
			// else
		}
	// mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}


int	main(int argc, char **argv)
{
	static t_vars	vars;

	if (!check_map(argv[1], init_mapstruct(map())))
		return (0);
	// player()->x = map()->pstart[0];
	// player()->y = map()->pstart[1];
	player()->x = 15;
	player()->y = 15;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE), "Hello world!");	
	vars.img.img = mlx_new_image(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE));
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	init_hooks(&vars);
	init_images(&vars);
	(sprite()->img) = mlx_xpm_file_to_image(vars.mlx, "sprites/swimmer.xpm", &sprite()->width, &sprite()->height);
	sprite()->addr = mlx_get_data_addr(sprite()->img, &sprite()->bits_per_pixel, &sprite()->line_length, &sprite()->endian);
	test_canvas(&vars, *img_list(), map()->height_y, map()->width_x);
	mlx_loop(vars.mlx);
}
	// 

	// vars.win = mlx_new_window(vars.mlx, (map()->height_y * 63), 
	//(map()->width_x * 63) , "Hello world!");
// void	do_nothing(t_vars *vars)
// {
// 	return ;
// }

// exe	*t(void)
// {
// 	static exe	f[2] = {
// 		do_nothing,
// 		end_game		
// 	};

/*
	mlx_init
	
	mlx_put_image_to_window
	mlx_xpm_file_to_image
	mlx_destroy_image
	mlx_xpm_to_image
	mlx_new_image
	mlx_pixel_put
	
	mlx_destroy_display
	mlx_clear_window
	mlx_new_window
	
	mlx_do_sync
	
	
	mlx_get_color_value
	mlx_get_screen_size
	mlx_get_data_addr
	
	mlx_do_key_autorepeatoff
	mlx_do_key_autorepeaton
	
	mlx_expose_hook
	mlx_key_hook
	mlx_hook
	
	mlx_loop_end
	mlx_loop
	
	mlx_mouse_get_pos
	mlx_mouse_hide
	mlx_mouse_hook
	mlx_mouse_move
	mlx_mouse_show
	
	mlx_string_put
	mlx_set_font
	MLX_H

*/