/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/05 20:23:16 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_matrix_map(t_map *map)
{
	char **bmap;
	int	fd;
	int	i;

	i = 0;
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
		i++;
	}
	map->space = bmap;
	return (1);
}

int	read_map(t_map *map)
{
	int fd;
	char	*gnl;
	int	i;


	i = 0;
	fd = open(map->path_ber, O_RDONLY);
	gnl = NULL;
	if (fd < 0)
		return (1);
	gnl = get_next_line(fd);
	while (i>-1)
	{
		if (i == 0)
		{
			map->ncol = ft_strlen(gnl) -1;
			map->nrow++;
		}
		if(!get_next_line(fd))
			break ;
		else
			map->nrow++;
		i++;
	}
	if((HEIGHT / map->nrow) >= (WIDTH / map->ncol))
		map->len = WIDTH / map->ncol;
	else
		map->len = HEIGHT / map->nrow;
	if (build_matrix_map(map))
		return (0);
	return (1);
}
