/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/25 15:38:02 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	construct_image_earth(t_game *game, t_image *image)
{
	image->earth_tex = mlx_load_png(EARTH);
	image->earth = mlx_texture_to_image(game->mlx, image->earth_tex);
	mlx_resize_image(image->earth, 130, 130);
}


void	construct_image_mapb(t_game *game, t_image *image)
{
	image->mapb_tex = mlx_load_png(MAPB);
	image->mapb = mlx_texture_to_image(game->mlx, image->mapb_tex);
	mlx_resize_image(image->mapb, 130, 130);
}


void	construct_image_rock(t_game *game, t_image *image)
{
	image->rock_tex = mlx_load_png(ROCK);
	image->rock = mlx_texture_to_image(game->mlx, image->rock_tex);
	mlx_resize_image(image->rock, 130, 130);
}


void	construct_image_rocket(t_game *game, t_image *image)
{
	image->rocket_tex = mlx_load_png(ROCKET);
	image->rocket = mlx_texture_to_image(game->mlx, image->rocket_tex);
	mlx_resize_image(image->rocket, 130, 130);
}

void	construct_image_collect(t_game *game, t_image *image)
{
	image->collect_tex = mlx_load_png(COLLECT);
	image->collect = mlx_texture_to_image(game->mlx, image->collect_tex);
	mlx_resize_image(image->collect, 130, 130);
}
