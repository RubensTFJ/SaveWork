/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:42:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/02 19:14:46 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_object *player(void)
{
	static t_object pisciner;

	return (&pisciner);
}

char	*on(int press)
{
	static char keyboard[70000];

	return (&keyboard[press]);
}

t_list	**obj_list(void)
{
	static t_list	*list;

	return (&list);
}

t_object	**move_list(void)
{
	static t_object	*ob;

	return (&ob);
}
/*
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