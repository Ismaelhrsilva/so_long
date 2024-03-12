/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/12 20:05:43 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static void	get_map_elements(char *bmap_i, t_map *map, int i)
{
	int	p;

	p = 0;
	map->ncollect += count_char(bmap_i, 'C');
	map->nexit += count_char(bmap_i, 'E');
	map->nplayer += count_char(bmap_i, 'P');
	map->nenemy += count_char(bmap_i, 'A');
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
		return (ft_putstr_fd("Erro\nNot possible do build map", 2), 1);
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
	if (right_number_objects(map))
		return (close(fd), 0);
	if (valid_path(map))
		return (close(fd), 0);
	return (close(fd), 1);
}

static void	len_image(t_map *map)
{
	if ((HEIGHT / map->nrow) >= (WIDTH / map->ncol))
		map->len = WIDTH / map->ncol;
	else
		map->len = HEIGHT / map->nrow;
}

static int	valid_big_map(t_map *map)
{
	if (map->nrow >= 410 || map->ncol >= 465)
	{
		ft_putstr_fd("Error\nMap to big", 2);
		return (1);
	}
	else
		return (0);
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
	if (valid_big_map(map))
		return (1);
	len_image(map);
	if (build_matrix_map(map))
		return (0);
	return (1);
}
