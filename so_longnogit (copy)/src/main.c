/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:14 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/03 19:18:59 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	end_img_list()
{
	return ;
}

int	end_game(t_vars *vars)
{
	// end_img_list(*img_list());
	mlx_destroy_image(vars->mlx, vars->img.img);
	// mlx_destroy_image(vars->mlx, sprite()->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(map());
	exit(0);
	return (0);
}

int	update(t_vars *vars)
{
	// movement(vars);
	(void *)vars;
	return (0);
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
		while (iterate->next)
			iterate = iterate->next;
		iterate->next = new;
	}
}

void	init_objects(t_vars *vars, t_infomap *map)
{
	int		i;
	int		j;

	map->grid = calloc(sizeof(t_object *), map->height_y);
	i = -1;
	while (++i < map->height_y)
	{
		map->grid[i] = calloc(sizeof(t_object *), map->width_x);
		j = -1;
		while (++j < map->width_x)
		{
			if (map->map[i][j] == '1')
				map->grid[i][j] = create_object("sprites/ground.xpm", vars, map->map[i][j]);
			else if (map->map[i][j] == '0')
				map->grid[i][j] = create_object("sprites/ground.xpm", vars, map->map[i][j]);
			else if (map->map[i][j] == 'P')
				map->grid[i][j] = create_object("sprites/swimmer.xpm", vars, map->map[i][j]);
			// else if (map->map[i][j] == 'C')
			// 	map->grid[i][j] = create_object("sprites/collectable.xpm", vars, map->map[i][j]);
			// else if (map->map[i][j] == 'M')
			// 	map->grid[i][j] = create_object("sprites/enemy.xpm", vars, map->map[i][j]);
			// else if (map->map[i][j] == 'E')
			// 	map->grid[i][j] = create_object("sprites/exit.xpm", vars, map->map[i][j]);
		}
	}
}

t_object	*create_object(char *path, t_vars *vars, int id)
{
	t_object	*obj;
	
	obj = calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, path, &obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel, &obj->data.line_length, &obj->data.endian);
	if (id == 'P' || id == 'M')
		obj->new_pos = movement;
	return (obj);
}

t_object	**this(void)
{
	static t_object	*element;

	return (&element);
}

t_object	*get_object(t_list *list, int tifier)
{
	while (list->obj.id != tifier)
		list = list->next;
	*this() = (&(list->obj));
	return (&(list->obj));
}

void	do_nothing(t_vars *vars)
{
	return ;
}

void	set_new_object(t_object *obj)
{
	obj->id = -1;
	obj->x = -1;
	obj->y = -1;
	// obj->new_pos = do_nothing;
	// obj->trail = do_nothing;
	obj->animation = 0;
	obj->data.addr = 0;
	obj->data.bits_per_pixel = 0;
	obj->data.endian = 0;
	obj->data.img = NULL;
	obj->data.line_length = 0;
	obj->data.height = 0;
	obj->data.width = 0;
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_down, &vars);
	mlx_hook(vars->win, 3, 1L << 1, key_up, &vars);
	mlx_loop_hook(vars->mlx, update, &vars);
}

void	make_frame(t_vars *vars, t_infomap *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height_y)
	{
		j = -1;
		while (++j < map->width_x)
		{
			if (map->grid[i][j])
				put_ground(vars, map->grid[i][j] , i, j);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	static t_vars	vars;

	if (!check_map(argv[1], init_mapstruct(map())))
		return (0);
	vars.mlx = mlx_init();
	// init_hooks(&vars);
	vars.win = mlx_new_window(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE), "Hello world!");	
	vars.img.img = mlx_new_image(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE));
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	init_objects(&vars, map());
	make_frame(&vars, map());
	mlx_loop(vars.mlx);
}

// int	main(int argc, char **argv)
// {
// 	static t_vars	vars;

// 	if (!check_map(argv[1], init_mapstruct(map())))
// 		return (0);
// 	// player()->x = map()->pstart[0] * 64;
// 	// player()->y = map()->pstart[1] * 64;
// 	vars.mlx = mlx_init();
// 	init_hooks(&vars);
// 	vars.win = mlx_new_window(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE), "Hello world!");	
// 	vars.img.img = mlx_new_image(vars.mlx, (map()->width_x * SCALE), (map()->height_y * SCALE));
// 	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
// 	init_objects(&vars, map());
// 	make_frame(map(), &vars, map());
// }
	// (sprite()->img) = mlx_xpm_file_to_image(vars.mlx, "sprites/swimmer.xpm", &sprite()->width, &sprite()->height);
	// sprite()->addr = mlx_get_data_addr(sprite()->img, &sprite()->bits_per_pixel, &sprite()->line_length, &sprite()->endian);
	// mlx_loop(vars.mlx);

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