/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:50:47 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/09 21:06:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	if (x < data->height && x >= 0 && y < (data->width * SCALE) && y >= 0)
		dst = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
	else
		return (0);
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_clear(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < (map()->width_x * SCALE) && x >= 0 && (y < (map()->height_y * SCALE) && y >= 0))
	{	
		dst = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	// if (color < 0x00000f00)
	// 	return ;
	if (x < (map()->width_x * SCALE) && x >= 0 && (y < (map()->height_y * SCALE) && y >= 0))
	{	
		dst = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
