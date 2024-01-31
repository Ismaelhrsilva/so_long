/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/31 20:58:25 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	position_validation(t_main *main, int x, int y)
{
	int 	i;
	int	j;
	int	signal;

	j = main->map->x_player;
	i = main->map->y_player;
	signal = -1;
	if (x > 0 || y > 0)
		signal = 1;
	if ((x == 0 && y < 0) || (x == 0 && y > 0))
	{
		if(!ft_memchr("1", main->map->build_map[i + signal][j], 1))
			main->map->y_player = main->map->y_player + signal;
		else
			return (0);
	}
	else if ((x > 0 && y == 0) || (x < 0 && y == 0))
	{
		if(!ft_memchr("1", main->map->build_map[i][j + signal], 1))
			main->map->x_player = main->map->x_player + signal;
		else
			return (0);
	}
	else
		return (1);
}

static void	step(t_main *main, int x, int y)
{
	ft_printf("Linha: %d, Coluna: %d\n", main->map->y_player, main->map->x_player);
	if(position_validation(main, x, y))
	{
		main->image->rocket->instances[0].y += y;
		main->image->rocket->instances[0].x += x;
	}
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
