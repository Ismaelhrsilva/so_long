/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:01:11 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/06 20:01:45 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char_prohibited(t_map *map, char *str)
{
	int	wall;
	int	back;
	int	total_c;
	int	allowed_c;

	total_c = map->ncol;
	wall = count_char(str, '1');
	back = count_char(str, '0');
	allowed_c = count_char(str, 'P') + count_char(str, 'C') + 
		count_char(str, 'E') + wall + back;
	if (total_c != allowed_c)
	{
		ft_printf("Letter prohibited");
		return (1);
	}
	else
		return (0);
}

int	right_number_objects(t_main *main)
{
	if (main->map->ncollect < 1)
	{
		ft_printf("No collectables enought !!!");
		return (1);
	}
	if (main->map->nexit != 1)
	{
		ft_printf("there is not 1 exit !!!");
		return (1);
	}
	if (main->map->nplayer != 1)
	{
		ft_printf("There is not 1 player !!!");
		return (1);
	}
	return (0);
}

int	right_ber(t_main *main)
{
	int	len;
	char	*ber;
	int	fd;
	char	*buffer;

	len = ft_strlen(main->map->path_ber);
	ber = &main->map->path_ber[len - 4];
	fd = open(main->map->path_ber, O_RDONLY);
	buffer = malloc(10 * sizeof(char));
	if (buffer == NULL)
		return (1);
	if (fd <= 0)
	{
		ft_printf("Is was not possible to open the map");
		return (close(fd), 1);
	}
	if (read(fd, buffer, 1) < 0)
		return (ft_printf("Is not a file"), 1);
	if (ft_strncmp(ber, ".ber", 4))
		return (ft_printf("Is not a .BER file"), 1);
	if (read(fd, buffer, 1) == 0)
		return (ft_printf("Is empty"), 1);
	return (free(buffer), close(fd), 0);
}

int	map_format(t_map *map, char *str)
{
	int	len;

	len = ft_strlenspace(str) -1;
	if (ft_strlenspace(str) != map->ncol)
		return (ft_printf("Lines with differents sizes"),1);
	if (!(map->ncol * map->nrow >= 15 && map->nrow >= 3 && map->ncol >= 3))
		return (ft_printf("Map smaller than possible"), 1);
	while (map->row_v <= map->nrow)
	{
		if ((map->row_v == 0 || map->row_v == map->nrow)
			&& count_char(str, '1') != map->ncol)
			return (ft_printf("Error\nWall does not complety filled with 1"), 1);
		else if (map->row_v != map->nrow && (str[0] != '1' || str[len] !='1'))
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
	int	x;
	int	y;

	i = 0;
	x = map->x_player;
	y = map->y_player;
	fill_path(map->space, x, y);
	while (i < map->nrow)
	{
		ft_printf("%s\n", map->space[i]);
		if (count_char(map->space[i], 'C') || count_char(map->space[i], 'E'))
			return (ft_printf("Error\nNo path to collectable or exit"), 1);
		j = 0;
		while (map->space[i][j])
		{
			if (map[x][y] == 'o')
				map[x][y] = '0';
			else if (map[x][y] == 'c')
				map[x][y] = 'C';
			else if (map[x][y] == 'e')
				map[x][y] = 'E';
			j++;
		}
		i++;
	}
	return (0);
}


