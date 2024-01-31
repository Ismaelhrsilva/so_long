/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/31 18:59:09 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_window(t_image *image, t_game	*game, t_map *map)
{
	int	row;
	int	col;
	int	len;

	row = 0;
	len = map->len_image;
	mlx_image_to_window(game->mlx, image->mapb, 0, 0);
	while (row < map->nrow)
	{
		col = 0;
		while (col < map->ncol)
		{
			if (map->build_map[row][col] == '1')
				mlx_image_to_window(game->mlx, image->rock, col * map->len_image , row * map->len_image);
			if (map->build_map[row][col] == 'C')
				mlx_image_to_window(game->mlx, image->collect, col * map->len_image , row * map->len_image);
				if (map->build_map[row][col] == 'E')
				mlx_image_to_window(game->mlx, image->earth, col * map->len_image , row * map->len_image);
				if (map->build_map[row][col] == 'P')
				{	
					map->x_player = col;
					map->y_player = row;
				}
			col++;
		}
		row++;
	}
	mlx_image_to_window(game->mlx, image->rocket, map->x_player * map->len_image , map->y_player * map->len_image);

}

void	put_image(t_game *game, t_map *map, t_image *image)
{
	construct_image_earth(game, image, map);
	construct_image_mapb(game, image);
	construct_image_rock(game, image, map);
	construct_image_rocket(game, image, map);
	construct_image_collect(game, image, map);
	put_image_window(image, game, map);
}


int	main(int argc, char **argv)
{
	t_main	*main;
	int	len;

	if (argc != 2)
		return (0);
	main = init_main();


	main->map = init_map();
	main->game = init_game();
	main->image = init_image();
	main->map->path_ber = argv[1];
	read_map(&argv[1], main->map);
	len = main->map->len_image;
	main->game->mlx = mlx_init(len * main->map->ncol, len * main->map->nrow, "So_Long", true); 
	//main->game->mlx = mlx_init(1920, 1080, "So_Long", true); 
	if (!main->game->mlx)
		return (0);
	put_image(main->game, main->map, main->image);
	mlx_key_hook(main->game->mlx, &ft_hook, main);
	mlx_loop(main->game->mlx);
	mlx_terminate(main->game->mlx);
	return (0);
}
