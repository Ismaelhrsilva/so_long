/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/31 18:26:35 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//static void	rocket_position()




static void	step(t_main *main, int x, int y)
{
	main->image->rocket->instances[0].y += y;
	main->image->rocket->instances[0].x += x;
}

void	ft_hook(mlx_key_data_t keydata, void* param)
{
	t_main	*main;

	main = (t_main *) param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		step(main, 0, -SIZE);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		step(main, 0, SIZE);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		step(main, -SIZE, 0);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		step(main, SIZE, 0);
}
