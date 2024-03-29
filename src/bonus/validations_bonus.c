/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:01:11 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/13 21:15:56 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

int	right_number_objects(t_map *map)
{
	if (map->ncollect < 1)
	{
		ft_putstr_fd("Error\nNo collectables enought", 2);
		return (1);
	}
	if (map->nexit != 1)
	{
		ft_putstr_fd("Error\nthere is not 1 exit", 2);
		return (1);
	}
	if (map->nplayer != 1)
	{
		ft_putstr_fd("Error\nThere is not 1 player", 2);
		return (1);
	}
	return (0);
}

int	right_ber(t_main *main)
{
	int		len;
	char	*ber;
	int		fd;
	char	*buffer;

	len = ft_strlen(main->map->path_ber);
	ber = &main->map->path_ber[len - 4];
	fd = open(main->map->path_ber, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nIs was not possible to open the map", 2);
		return (close(fd), 1);
	}
	buffer = malloc(10 * sizeof(char));
	if (buffer == NULL)
		return (1);
	if (read(fd, buffer, 1) < 0)
		return (free(buffer), ft_putstr_fd("Error\nIs not a file", 2), 1);
	if (ft_strncmp(ber, ".ber", 4))
		return (free(buffer), ft_putstr_fd("Error\nIs not a .BER file", 2), 1);
	if (read(fd, buffer, 1) == 0)
		return (free(buffer), ft_putstr_fd("Error\nIs empty", 2), 1);
	return (free(buffer), close(fd), 0);
}

int	map_format(t_map *map, char *str)
{
	int	len;

	len = ft_strlenspace(str) -1;
	if (ft_strlenspace(str) != map->ncol)
		return (ft_putstr_fd("Error\nLines with differents sizes", 2), 1);
	if (!(map->ncol * map->nrow >= 15 && map->nrow >= 3 && map->ncol >= 3))
		return (ft_putstr_fd("Map smaller than possible", 2), 1);
	while (map->row_v <= map->nrow)
	{
		if ((map->row_v == 0 || map->row_v == map->nrow - 1)
			&& count_char(str, '1') != map->ncol)
			return (ft_putstr_fd("Error\nWall does not complety filled with 1",
					2), 1);
		else if (map->row_v != map->nrow && (str[0] != '1' || str[len] != '1'))
			return (ft_putstr_fd("Error\nWall does not complety filled with 1",
					2), 1);
		map->row_v ++;
		break ;
	}
	return (0);
}

static void	fill_path(char **map, int y, int x)
{
	if (map[y][x] != 'P')
	{
		if (map[y][x] == '0')
			map[y][x] = 'o';
		else if (map[y][x] == 'C')
			map[y][x] = 'c';
		else if (map[y][x] == 'E')
			map[y][x] = 'e';
		else
			return ;
	}
	fill_path(map, y + 1, x);
	fill_path(map, y - 1, x);
	fill_path(map, y, x + 1);
	fill_path(map, y, x - 1);
}

int	valid_path(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	fill_path(map->space, map->y_player, map->x_player);
	while (i < map->nrow)
	{
		if (count_char(map->space[i], 'C') || count_char(map->space[i], 'E'))
			return (ft_putstr_fd("Error\nNo path to collectable or exit", 2), 1);
		j = 0;
		while (map->space[i][j])
		{
			if (map->space[i][j] == 'o')
					map->space[i][j] = '0';
			else if (map->space[i][j] == 'c')
				map->space[i][j] = 'C';
			else if (map->space[i][j] == 'e')
				map->space[i][j] = 'E';
			j++;
		}
		i++;
	}
	return (0);
}
