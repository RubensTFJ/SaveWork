/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:14 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/11 19:47:40 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	end_img_list()
{
	return ;
}

void	free_matrix(t_vars *game, t_infomap *map)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < map->height_y)
	{
		j = -1;
		while (++j < map->width_x)
			mlx_destroy_image(game->mlx, map->grid[i][j]->data.img);
			free(map->grid[i][j]);
	}
	free_map(map);
}

void	free_list(t_vars *game, t_object *list)
{
	if (list->on_top)
		free_list(game, list->on_top);
	mlx_destroy_image(game->mlx, list->data.img);
	free(list);
	list = NULL;
}

int	end_game(t_vars *game)
{
	free_matrix(game, map());
	free_list(game, *obj_list());
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(0);
	return (0);
}

void	listadd_objback(t_object **lst, t_object *new)
{
	t_object	*iterate;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		iterate = *lst;
		while (iterate->on_top)
			iterate = iterate->on_top;
		iterate->on_top = new;
	}
}


t_object	**this(void)
{
	static t_object	*element;

	return (&element);
}

t_object	*get_object(t_object *list, int tifier)
{
	while (list->id != tifier)
		list = list->on_top;
	*this() = (list);
	return (list);
}

void	do_nothing(t_vars *vars)
{
	return ;
}

void	put_active_objects(t_vars *game, t_object *obj)
{
	while (obj)
	{
		if (obj->new_pos)
			obj->new_pos(game, obj);
		ground_to_image(game, obj);
		// obj->print(game, obj);
		obj = obj->on_top;
	}
}

void	make_frame(t_vars *game, t_infomap *map)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < map->height_y)
	{
		j = -1;
		while (++j < map->width_x)
			ground_to_image(game, map->grid[i][j]);
	}
}

int	update(t_vars *game)
{
	make_frame(game, map());
	put_active_objects(game, *obj_list());
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

void	init_hooks(t_vars *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_down, game);
	mlx_hook(game->win, 3, 1L << 1, key_up, game);
	mlx_loop_hook(game->mlx, update, game);
}

void	init_game(t_vars *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map()->width_x * SCALE), (map()->height_y * SCALE), "Hello world!");	
	game->img.img = mlx_new_image(game->mlx, (map()->width_x * SCALE), (map()->height_y * SCALE));
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);

}

int	main(int argc, char **argv)
{
	static t_vars	game;

	if (!check_map(argv[1], init_mapstruct(map())))
		return (0);
	init_game(&game);
	init_floor_objects(&game, map());
	init_hooks(&game);
	mlx_loop(game.mlx);
}

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