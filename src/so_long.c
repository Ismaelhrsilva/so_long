/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/06 21:05:50 by ishenriq         ###   ########.org.br   */
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
	col = 0;
	len_width = WIDTH / map->ncol;
	len_height = HEIGHT / map->nrow;
	while (row <= map->nrow)
	{
		while (col <= map->ncol)
		{
			//if (map->build_map[row][col] == 1)
			if (1)
				mlx_image_to_window(game->mlx, image->background,
						(row * len_width) , (col * len_height));
			col++;
		}
		row++;
	}
}

void	put_image(t_game *game, t_map *map)
{
	t_image	*image;

	image = init_image();

	image->background_tex = mlx_load_png(BACKGROUND);
	image->earth_tex = mlx_load_png(EARTH);
	image->rock_tex = mlx_load_png(ROCK);
	image->rocket_tex = mlx_load_png(ROCKET);
	if (!image->background_tex)
		return ;
	
	image->background = mlx_texture_to_image(game->mlx, image->background_tex);
	image->earth = mlx_texture_to_image(game->mlx, image->earth_tex);
	image->rock = mlx_texture_to_image(game->mlx, image->rock_tex);
	image->rocket = mlx_texture_to_image(game->mlx, image->rocket_tex);
	if (!image->background)
		return ;
	
	mlx_resize_image(image->background, (WIDTH / map->nrow), (HEIGHT / map->ncol));
	mlx_resize_image(image->earth, (WIDTH / map->nrow), (HEIGHT / map->ncol));
	mlx_resize_image(image->rock, (WIDTH / map->nrow), (HEIGHT / map->ncol));
	mlx_resize_image(image->rocket, (WIDTH / map->nrow), (HEIGHT / map->ncol));

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
	map->path_ber = argv[1];
	read_map(&argv[1], map);
	game->mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!game->mlx)
		return (0);

	put_image(game, map);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
