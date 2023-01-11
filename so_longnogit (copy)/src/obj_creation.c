/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:22:57 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/11 20:09:51 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_floor_objects(t_vars *vars, t_infomap *map)
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
			if (map->map[i][j] == '1' || map->map[i][j] == '/')
				map->grid[i][j] = create_object_1(vars, '1', i, j);
			else
			{
				map->grid[i][j] = create_object_0(vars, '0', i, j);
				map->grid[i][j]->on_top = object_type(vars, map->map[i][j], i, j);
				listadd_objback(obj_list(), map->grid[i][j]->on_top);
			}
		}
	}
}

t_object	*object_type(t_vars *vars, int id, int i, int j)
{
	if (id == '1')
		return (create_object_1(vars, id, i, j));
	// else if (id == '0')
	// 	return (create_object_0(vars, id, i, j));
	else if (id == 'C')
		return (create_object_C(vars, id, i, j));
	else if (id == 'P')
		return (create_object_P(vars, id, i, j));
	else if (id == 'E')
		return (create_object_E(vars, id, i, j));
	else if (id == 'M')
		return (create_object_M(vars, id, i, j));
	return (NULL);
}

t_object	*create_object_1(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;
	
	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm", &obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel, &obj->data.line_length, &obj->data.endian);
	obj->data.height = obj->data.height / 16;
	obj->x = i;
	obj->y = j;
	return (obj);
}

t_object	*create_object_0(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;
	
	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/ground.xpm", &obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel, &obj->data.line_length, &obj->data.endian);
	obj->x = i;
	obj->y = j;
	return (obj);
}

t_object	*create_object_C(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;
	
	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/collectable.xpm", &obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel, &obj->data.line_length, &obj->data.endian);
	obj->x = i;
	obj->y = j;
	return (obj);
}

t_object	*create_object_P(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;
	
	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/swimmer.xpm", &obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel, &obj->data.line_length, &obj->data.endian);
	obj->data.height = 32;
	obj->data.width = 48;
	obj->new_pos = movement;
	obj->x = i;
	obj->y = j;
	return (obj);
}

t_object	*create_object_E(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;
	
	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm", &obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel, &obj->data.line_length, &obj->data.endian);
	obj->x = i;
	obj->y = j;
	return (obj);
}

t_object	*create_object_M(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;
	
	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/enemy.xpm", &obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel, &obj->data.line_length, &obj->data.endian);
	// obj->new_pos = movement;
	obj->x = i;
	obj->y = j;
	return (obj);
}

void	set_new_object(t_object *obj)
{
	obj->new_pos = NULL;
	obj->data.addr = NULL;
	obj->data.img = NULL;
}