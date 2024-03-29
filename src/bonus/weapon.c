/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/18 18:18:20 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static void	ft_bullet_pos(t_main *main, int len)
{
	if (main->map->bullet_direction == 'r')
	{
		main->map->x_bullet += 2;
		main->img->weapon->instances[main->map->w].x += 2 * len;
	}
	if (main->map->bullet_direction == 'l')
	{
		main->map->x_bullet -= 2;
		main->img->weapon->instances[main->map->w].x -= 2 * len;
	}
	if (main->map->bullet_direction == 'u')
	{
		main->map->y_bullet -= 2;
		main->img->weapon->instances[main->map->w].y -= 2 * len;
	}
	if (main->map->bullet_direction == 'd')
	{
		main->map->y_bullet += 2;
		main->img->weapon->instances[main->map->w].y += 2 * len;
	}
}

static void	ft_shooting(t_main *main, int len)
{
	while (main->map->step < main->map->depth)
	{
		if (main->map->step == main->map->i)
		{
			ft_bullet_pos(main, len);
			main->map->i++;
		}
		break ;
	}
	if (main->map->step == main->map->depth)
	{
		main->img->weapon->instances[main->map->w].enabled = false;
		main->map->w++;
		main->map->firing = 0;
		main->map->x_bullet = 0;
		main->map->y_bullet = 0;
	}
}

void	ft_fire(t_main *main)
{
	if (main->map->firing == 1)
	{
		if (main->map->depth - main->map->step == 3 && main->map->bullets == 1)
		{
			main->map->x_bullet = main->map->x_player;
			main->map->y_bullet = main->map->y_player;
			main->map->len_x_bullet = main->map->x_bullet * main->map->len;
			main->map->len_y_bullet = main->map->y_bullet * main->map->len;
			if (mlx_image_to_window(main->mlx, main->img->weapon,
					main->map->len_x_bullet, main->map->len_y_bullet) < 0)
				return (ft_putstr_fd("Error\nPut image fails", 2));
			main->map->i = main->map->step;
			main->map->bullets = 0;
			main->map->bullet_direction = main->map->direction;
		}
		ft_shooting(main, main->map->len);
	}
}
