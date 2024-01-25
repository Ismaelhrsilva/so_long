/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/22 22:36:14 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_window(t_image *image, t_game	*game, t_map *map)
{
	int	row;
	int	col;
	int	len_width;
	int	len_height;

	row = 0;

	//len_width = WIDTH / map->ncol;
	//len_height = HEIGHT / map->nrow;
	while (row < map->nrow)
	{
		col = 0;
		while (col < map->ncol)
		{
			//if (map->build_map[row][col] == 1)
			if (1)
				mlx_image_to_window(game->mlx, image->earth,
						row * map->len_image , col * map->len_image);
			col++;
		}
		row++;
	}
}

void	resize_image(t_image *image, t_map *map)
{
	mlx_resize_image(image->mapb, map->len_image, map->len_image);
	mlx_resize_image(image->earth , map->len_image, map->len_image);
	mlx_resize_image(image->rock , map->len_image, map->len_image);
	mlx_resize_image(image->rocket , map->len_image, map->len_image);
}

void	put_image(t_game *game, t_map *map, t_image *image)
{
	image->earth_tex = mlx_load_png(EARTH);
	image->mapb_tex = mlx_load_png(MAPB);
	image->rock_tex = mlx_load_png(ROCK);
	image->rocket_tex = mlx_load_png(ROCKET);
	if (!image->mapb_tex)
		return ;
	
	image->earth = mlx_texture_to_image(game->mlx, image->earth_tex);
	image->mapb = mlx_texture_to_image(game->mlx, image->mapb_tex);
	image->rock = mlx_texture_to_image(game->mlx, image->rock_tex);
	image->rocket = mlx_texture_to_image(game->mlx, image->rocket_tex);
	if (!image->mapb)
		return ;
	if (map->ncol >= map->nrow)
		map->len_image = HEIGHT / map->nrow;
	else
		map->len_image = WIDTH/ map->ncol;
	resize_image(image, map);
	put_image_window(image, game, map);
}


int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;
	t_image	*image;


	if (argc != 2)
		return (0);
	map = init_map();
	game = init_game();
	image = init_image();
	map->path_ber = argv[1];
	read_map(&argv[1], map);
	game->mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!game->mlx)
		return (0);

	put_image(game, map, image);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}