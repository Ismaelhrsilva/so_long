/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:01:11 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/08 20:21:31 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	right_number_objects(t_main *main)
{
	if (main->map->ncollect < 1)
	{
		ft_printf("Error\nNo collectables enought !!!");
		return (1);
	}
	if (main->map->nexit != 1)
	{
		ft_printf("Error\nthere is not 1 exit !!!");
		return (1);
	}
	if (main->map->nplayer != 1)
	{
		ft_printf("Error\nThere is not 1 player !!!");
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
		ft_printf("Error\nIs was not possible to open the map");
		return (close(fd), 1);
	}
	buffer = malloc(10 * sizeof(char));
	if (buffer == NULL)
		return (1);
	if (read(fd, buffer, 1) < 0)
		return (free(buffer), ft_printf("Error\nIs not a file"), 1);
	if (ft_strncmp(ber, ".ber", 4))
		return (free(buffer), ft_printf("Error\nIs not a .BER file"), 1);
	if (read(fd, buffer, 1) == 0)
		return (free(buffer), ft_printf("Error\nIs empty"), 1);
	return (free(buffer), close(fd), 0);
}

int	map_format(t_map *map, char *str)
{
	int	len;

	len = ft_strlenspace(str) -1;
	if (ft_strlenspace(str) != map->ncol)
		return (ft_printf("Error\nLines with differents sizes"), 1);
	if (!(map->ncol * map->nrow >= 15 && map->nrow >= 3 && map->ncol >= 3))
		return (ft_printf("Map smaller than possible"), 1);
	while (map->row_v <= map->nrow)
	{
		if ((map->row_v == 0 || map->row_v == map->nrow)
			&& count_char(str, '1') != map->ncol)
			return (ft_printf("Error\nWall does not complety filled with 1"), 1);
		else if (map->row_v != map->nrow && (str[0] != '1' || str[len] != '1'))
			return (ft_printf("Error\nWall does not complety filled with 1"), 1);
		map->row_v ++;
		break ;
	}
	return (0);
}

static void	fill_path(char **map, int x, int y)
{
	if (map[x][y] == '0')
		map[x][y] = 'o';
	else if (map[x][y] == 'C')
		map[x][y] = 'c';
	else if (map[x][y] == 'E')
		map[x][y] = 'e';
	else
		return ;
	fill_path(map, x + 1, y);
	fill_path(map, x - 1, y);
	fill_path(map, x, y + 1);
	fill_path(map, x, y - 1);
}

int	valid_path(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	fill_path(map->space, map->x_player, map->y_player);
	while (i < map->nrow)
	{
		if (count_char(map->space[i], 'C') || count_char(map->space[i], 'E'))
			return (ft_printf("Error\nNo path to collectable or exit"), 1);
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
