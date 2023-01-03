/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_later.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:22:32 by rteles-f          #+#    #+#             */
/*   Updated: 2022/12/10 22:11:29 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t n, size_t xsize)
{
	char		*new;
	size_t		i;

	n *= xsize;
	new = malloc(n);
	if (!new)
		return (NULL);
	i = 0;
	while (i < n)
		new[i++] = 0;
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	**copy_map(t_infomap *vmap)
{
	int		i;
	int		j;
	char	**copy;

	if (!vmap)
		return (NULL);
	copy = ft_calloc(sizeof(char *), (vmap->height_y + 1));
	i = -1;
	while (vmap->map[++i])
	{
		copy[i] = ft_calloc(sizeof(char), (ft_strlen(vmap->map[i]) + 1));
		j = -1;
		while (vmap->map[i][++j])
			copy[i][j] = vmap->map[i][j];
	}
	return (copy);
}
