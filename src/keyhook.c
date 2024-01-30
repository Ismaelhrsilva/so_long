/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/30 19:35:38 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	step(t_game *game, int x, int y)
{
	game->image->rocket->instances[0].y += y;
	game->image->rocket->instances[0].x += x;
}

void ft_hook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		step(game, 0, -SIZE);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		step(game, 0, SIZE);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		step(game, -SIZE, 0);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		step(game, SIZE, 0);
}
