/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:15:06 by rteles-f          #+#    #+#             */
/*   Updated: 2022/12/29 21:26:31 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_player *player(void)
{
	static t_player pisciner;

	return (&pisciner);
}

char	*on(int press)
{
	static char keyboard[70000];

	return (&keyboard[press]);
}

t_data	*sprite(void)
{
	static t_data	sprites;
	
	return (&sprites);
}


t_list	**img_list(void)
{
	static t_list	*list;

	return (&list);
}

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
/*
t_list l()
{
	int		marker;
	t_list	*next;
	t_data	*the;
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