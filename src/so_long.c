/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/30 19:36:00 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_window(t_image *image, t_game	*game, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	mlx_image_to_window(game->mlx, image->mapb, col *SIZE, row *SIZE);
	while (row < map->nrow)
	{
		col = 0;
		while (col < map->ncol)
		{
			if (map->build_map[row][col] == '1')
				mlx_image_to_window(game->mlx, image->rock, col * SIZE , row * SIZE);
			if (map->build_map[row][col] == 'C')
				mlx_image_to_window(game->mlx, image->collect, col * SIZE , row * SIZE);
				if (map->build_map[row][col] == 'E')
				mlx_image_to_window(game->mlx, image->earth, col * SIZE , row * SIZE);
				if (map->build_map[row][col] == 'P')
				{	
					mlx_image_to_window(game->mlx, image->rocket, col * SIZE , row * SIZE);
					map->x_player = col;
					map->y_player = row;
				}
			col++;
		}
		row++;
	}
}

void	put_image(t_game *game, t_map *map, t_image *image)
{
	construct_image_earth(game, image);
	construct_image_mapb(game, image);
	construct_image_rock(game, image);
	construct_image_rocket(game, image);
	construct_image_collect(game, image);
	put_image_window(image, game, map);
}


int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	if (argc != 2)
		return (0);
	map = init_map();
	game = init_game();
	game->image = init_image();
	map->path_ber = argv[1];
	read_map(&argv[1], map);
	game->mlx = mlx_init(SIZE * map->ncol, SIZE * map->nrow, "So_Long", true); 
	if (!game->mlx)
		return (0);
	put_image(game, map, game->image);
	mlx_key_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
