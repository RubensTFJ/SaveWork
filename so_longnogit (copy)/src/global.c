/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:42:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/11 19:32:18 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*on(int press)
{
	static char keyboard[70000];

	return (&keyboard[press]);
}

t_object	**obj_list(void)
{
	static t_object	*list;

	return (&list);
}

t_object	**move_list(void)
{
	static t_object	*ob;

	return (&ob);
}

/*
t_infomap l() {
	char		**map;
	int			width_x;
	int			height_y;
	int			exit[2];
	int			pstart[2];
	int			collectables[2];
	t_object	***grid;
	{
		int			id;
		double		x;
		double		y;
		void		(*new_pos)(t_vars *vars, t_object *obj);
		void		(*print)(t_vars *vars, t_object *obj);
		int			animation;		
		t_object	*on_top;
		t_data	data;
			{
				void	*img;
				char	*addr;
				int		bits_per_pixel;
				int		line_length;
				int		endian;
				int		width;
				int		height;
			}
	}
}	t_infomap;


t_data l()
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}

t_list l()
{
	int			marker;
	t_list		*next;
	t_object	*get;
	{
		char	id;
		double	x;
		double	y;
		t_data	my;
		{
			void	*img;
			char	*addr;
			int		bits_per_pixel;
			int		line_length;
			int		endian;
			int		width;
			int		height;
		}
	}
}

t_vars l() 
{
	void	*mlx;
	void	*win;
	t_data	img;
	{
		void	*img;
		char	*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
		int		width;
		int		height;
	}
	int		key;
}

*/