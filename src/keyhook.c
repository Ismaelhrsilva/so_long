/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/31 18:45:51 by ishenriq         ###   ########.org.br   */
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
	int	len;

	main = (t_main *) param;
	len = main->map->len_image;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		step(main, 0, -len);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		step(main, 0, len);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		step(main, -len, 0);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		step(main, len, 0);
}
