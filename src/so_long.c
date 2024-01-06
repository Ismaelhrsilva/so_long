/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/06 19:49:16 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map.h"

void	put_image(t_game *game)
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
	
	mlx_resize_image(image->background, 100, 100);
	if (mlx_image_to_window(game->mlx, image->background, 700, 0))
		return ;
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

	put_image(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
