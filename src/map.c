/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/08 21:07:47 by ishenriq         ###   ########.org.br   */
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
	map->space = bmap;
	while (i < map->nrow)
	{
		map->space[i] = get_next_line(fd);
		if (map_format(map, map->space[i]))
			return (0);
		if (count_char_prohibited(map, map->space[i]))
			return (0);
		get_map_elements(map->space[i], map, i);
		i++;
	}
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
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		map->ncol = ft_strlen(gnl) - 1;
		map->nrow++;
		free(gnl);
		i++;
	}
	close (fd);
	len_image(map);
	if (build_matrix_map(map))
		return (0);
	return (1);
}
