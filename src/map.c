/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/07 19:05:32 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_elements(char *bmap_i, t_map *map, int i)
{
	int	p;

	p = 0;
	map->ncollect += count_char(bmap_i, 'C');
	map->nexit += count_char(bmap_i, 'E');
	map->nplayer += count_char(bmap_i, 'P');
	if (count_char(bmap_i, 'P'))
	{
		map->y_player = i;
		while (bmap_i[p] != '\n')
		{
			if (bmap_i[p] == 'P')
				map->x_player = p;
			p++;
		}
	}
}

int	build_matrix_map(t_map *map)
{
	char	**bmap;
	int		fd;
	int		i;

	i = 0;
	fd = open(map->path_ber, O_RDONLY);
	bmap = ft_calloc((map->nrow + 1), sizeof(char *));
	if (!bmap)
		return (ft_printf("Erro\nNot possible do build map"), 1);
	while (i < map->nrow)
	{
		bmap[i] = get_next_line(fd);
		if (map_format(map, bmap[i]))
			return (0);
		if (count_char_prohibited(map, bmap[i]))
			return (0);
		get_map_elements(bmap[i], map, i);
		i++;
	}
	map->space = bmap;
	close(fd);
	if (valid_path(map))
		return (0);
	return (1);
}

static void	len_image(t_map *map)
{
	if ((HEIGHT / map->nrow) >= (WIDTH / map->ncol))
		map->len = WIDTH / map->ncol;
	else
		map->len = HEIGHT / map->nrow;
}

int	read_map(t_map *map)
{
	int		fd;
	char	*gnl;
	int		i;

	i = 0;
	fd = open(map->path_ber, O_RDONLY);
	if (fd < 0)
		return (1);
	gnl = get_next_line(fd);
	while (gnl)
	{
		map->ncol = ft_strlen(gnl) - 1;
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
