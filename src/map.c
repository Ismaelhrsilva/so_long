/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/04 18:00:51 by ishenriq         ###   ########.org.br   */
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
		map->ncollect += count_char(build_map[i], 'C');
		map->nexit += count_char(build_map[i], 'E');
		map->nplayer += count_char(build_map[i], 'P');
		i++;
	}
	map->space = build_map;
}

void	read_map(t_map *map)
{
	int fd;
	char	*gnl;
	int	i;


	i = 0;
	fd = open(map->path_ber, O_RDONLY);
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
	if((HEIGHT / map->nrow) >= (WIDTH / map->ncol))
		map->len = WIDTH / map->ncol;
	else
		map->len = HEIGHT / map->nrow;
	build_matrix_map(map);
}
