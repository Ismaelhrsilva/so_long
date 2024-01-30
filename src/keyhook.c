/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/30 17:58:35 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void ft_hook(t_game *game, t_image *image)
{

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		image->rocket->instances[0].y -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		image->rocket->instances[0].y += 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		image->rocket->instances[0].x -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		image->rocket->instances[0].x += 1;
}


/*void my_keyhook(void)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		step_up();
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		step_down();
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		step_left();
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		step_right();
}*/
