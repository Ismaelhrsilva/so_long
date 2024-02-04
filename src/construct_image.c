/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/04 15:17:10 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	construct_image_earth(t_main *main)
{
	main->img->earth_tex = mlx_load_png(EARTH);
	main->img->earth = mlx_texture_to_image(main->mlx, main->img->earth_tex);
	mlx_resize_image(main->img->earth, main->map->len, main->map->len);
}

void	construct_image_mapb(t_main *main)
{
	main->img->mapb_tex = mlx_load_png(MAPB);
	main->img->mapb = mlx_texture_to_image(main->mlx, main->img->mapb_tex);
	mlx_resize_image(main->img->mapb, WIDTH, HEIGHT);
}

void	construct_image_rock(t_main *main)
{
	main->img->rock_tex = mlx_load_png(ROCK);
	main->img->rock = mlx_texture_to_image(main->mlx, main->img->rock_tex);
	mlx_resize_image(main->img->rock, main->map->len, main->map->len);
}

void	construct_image_rocket(t_main *main)
{
	main->img->rocket_tex = mlx_load_png(ROCKET);
	main->img->rocket = mlx_texture_to_image(main->mlx, main->img->rocket_tex);
	mlx_resize_image(main->img->rocket, main->map->len, main->map->len);
}

void	construct_image_collect(t_main *main)
{
	main->img->collect_tex = mlx_load_png(COLLECT);
	main->img->collect = mlx_texture_to_image(main->mlx, main->img->collect_tex);
	mlx_resize_image(main->img->collect, main->map->len, main->map->len);
}
