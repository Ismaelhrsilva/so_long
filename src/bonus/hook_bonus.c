/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/18 18:21:51 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static void	ft_aux_player_image(t_main *main, int x, int y)
{
	if (x == 0 && y < 0)
	{
		main->map->direction = 'u';
		main->img->rocket_up->instances[0].enabled = true;
	}
	if (x == 0 && y > 0)
	{
		main->map->direction = 'd';
		main->img->rocket_down->instances[0].enabled = true;
	}
	if (x < 0 && y == 0)
	{
		main->map->direction = 'l';
		main->img->rocket_left->instances[0].enabled = true;
	}
	if (x > 0 && y == 0)
	{
		main->map->direction = 'r';
		main->img->rocket->instances[0].enabled = true;
	}
	main->map->step++;
}

static int	position_validation(t_main *main, int x, int y)
{
	int	i;
	int	j;
	int	signal;

	j = main->map->x_player;
	i = main->map->y_player;
	signal = -1;
	if (x > 0 || y > 0)
		signal = 1;
	if ((x == 0 && y < 0) || (x == 0 && y > 0))
	{
		if (!('1' == main->map->space[i + signal][j]))
			main->map->y_player = main->map->y_player + signal;
		else
			return (0);
	}
	else if ((x > 0 && y == 0) || (x < 0 && y == 0))
	{
		if (!('1' == main->map->space[i][j + signal]))
			main->map->x_player = main->map->x_player + signal;
		else
			return (0);
	}
	return (1);
}

static void	player_image(t_main *main, int x, int y)
{
	main->img->rocket->instances[0].enabled = false;
	main->img->rocket_up->instances[0].enabled = false;
	main->img->rocket_down->instances[0].enabled = false;
	main->img->rocket_left->instances[0].enabled = false;
	ft_aux_player_image(main, x, y);
	main->img->rocket->instances[0].y += y;
	main->img->rocket->instances[0].x += x;
	main->img->rocket_up->instances[0].y += y;
	main->img->rocket_up->instances[0].x += x;
	main->img->rocket_down->instances[0].y += y;
	main->img->rocket_down->instances[0].x += x;
	main->img->rocket_left->instances[0].y += y;
	main->img->rocket_left->instances[0].x += x;
}

static void	step(t_main *main, int x, int y)
{
	char	*number;
	char	*join;

	if (position_validation(main, x, y))
	{
		enemy_dies(main);
		is_collectable(main, main->map->x_player, main->map->y_player);
		walk_enemy(main);
		is_enemy(main, main->map->x_player, main->map->y_player);
		ft_exit(main, main->map->x_player, main->map->y_player);
		player_image(main, x, y);
		ft_fire(main);
		if (main->img->write_text)
			mlx_delete_image(main->mlx, main->img->write_text);
		number = ft_itoa(main->map->step);
		join = ft_strjoin("Number of movements ", number);
		main->img->write_text = mlx_put_string(main->mlx, join, 0, 0);
		if (!main->img->write_text)
			return ;
		if (mlx_resize_image(main->img->write_text, main->map->len * 2,
				main->map->len / 3) == 0)
			return ;
		free(number);
		free(join);
	}
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_main	*main;
	int		len;

	main = (t_main *) param;
	len = main->map->len;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(main->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		step(main, 0, -len);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		step(main, 0, len);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		step(main, -len, 0);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		step(main, len, 0);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		if (main->map->firing == 0)
		{
			main->map->depth = main->map->step + 3;
			main->map->firing = 1;
			main->map->bullets = 1;
		}
		ft_fire(main);
	}
}
