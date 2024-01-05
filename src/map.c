/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:52:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/05 20:35:08 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "so_long.h"

void	build_matrix_map(t_map *map)
{
	char **build_map;
	int	fd;
	int	i;

	i = 0;
	fd = open(map->path_ber, O_RDONLY);
	build_map = ft_calloc((map->nrow + 1) , sizeof(char));
	if (!build_map)
		return ;
	while (i <= map->nrow)
	{
		build_map[i] = ft_calloc((map->ncol + 1) , sizeof(char));
		if(!build_map[i])
			return ;
		build_map[i] = ft_memcpy(build_map[i], get_next_line(fd), map->ncol);
		i++;
		ft_printf("%s", build_map[i]);
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
	ft_printf("%d\n", map->ncol);
		ft_printf("%d\n", map->nrow);
}
