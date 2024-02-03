/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/03 10:36:32 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"





static	void	is_collectable(t_main *main, int x, int y)
{
	int	x_col;
	int	y_col;
	char	*type;
	int	n;
	static t_list	*aux;

	aux = main->list;
	while (aux)
	{
		x_col = ((t_pos *)aux->content)->x;
		y_col = ((t_pos *)aux->content)->y;
		type = ((t_pos *)aux->content)->type;
		n = ((t_pos *)aux->content)->n;
		if (x == x_col && y == y_col && !ft_memcmp(type, "C", 1))
		{
			if (main->image->collect->instances[n].enabled == true)
			{
				main->image->collect->instances[n].enabled = false;
				main->map->ncollect--;
			}
		}
		aux = aux->next;
	}
}

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
	if(position_validation(main, x, y))
	{
		is_collectable(main, main->map->x_player, main->map->y_player);
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
