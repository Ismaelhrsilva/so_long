/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/08 19:26:08 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_matrix_map(t_map *map)
{
	char **build_map;
	int	fd;
	int	i;

	i = 0;
	fd = open(map->path_ber, O_RDONLY);
	build_map = ft_calloc((map->nrow + 1) , sizeof(char *));
	if (!build_map)
		return ;
	while (i <= map->nrow)
	{
		build_map[i] = get_next_line(fd);
		ft_printf("%s", build_map[i]);
		i++;
	}
	map->build_map = build_map;
}

void	read_map(char **ber, t_map *map)
{
	int fd;
	char	*gnl;
	int	i;


	i = 0;
	fd = open(*ber, O_RDONLY);
	gnl = NULL;
	if (fd < 0)
		return ;
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
	if (map->ncol >= map->nrow)
		map->len_min = HEIGHT / map->nrow;
	else
		map->len_min = WIDTH/ map->ncol;
	build_matrix_map(map);
}
