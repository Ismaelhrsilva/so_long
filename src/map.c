/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/07 18:24:58 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_matrix_map(t_map *map)
{
	char **bmap;
	int	fd;
	int	i;
	int	p;

	i = 0;
	p = 0;
	fd = open(map->path_ber, O_RDONLY);
	bmap = ft_calloc((map->nrow + 1) , sizeof(char *));
	if (!bmap)
		return (1);
	while (i < map->nrow)
	{
		bmap[i] = get_next_line(fd);
		map->ncollect += count_char(bmap[i], 'C');
		map->nexit += count_char(bmap[i], 'E');
		map->nplayer += count_char(bmap[i], 'P');
		if (map_format(map, bmap[i]))
			return (0);
		if (count_char_prohibited(map, bmap[i]))
			return (0);
		if (count_char(bmap[i], 'P'))
		{
			map->y_player = i;
			while (bmap[i][p] != '\n')
			{
				if (bmap[i][p] == 'P')
					map->x_player = p;
				p++;
			}
		}
		i++;
	}
	map->space = bmap;
	if (valid_path(map))
		return (0);
	return (1);
}


static void	len_image(t_map *map)
{
	if((HEIGHT / map->nrow) >= (WIDTH / map->ncol))
		map->len = WIDTH / map->ncol;
	else
		map->len = HEIGHT / map->nrow;
}

int	read_map(t_map *map)
{
	int 	fd;
	char	*gnl;
	int	i;

	i = 0;
	fd = open(map->path_ber, O_RDONLY);
	if (fd < 0)
		return (1);
	gnl = get_next_line(fd);
	while (gnl)
	{
		map->ncol = ft_strlen(gnl) -1;
		map->nrow++;
		gnl = get_next_line(fd);
		i++;
	}
	close (fd);
	len_image(map);
	if (build_matrix_map(map))
		return (0);
	return (1);
}
