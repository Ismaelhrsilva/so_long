/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/15 21:04:29 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static void	ft_shooting(t_main *main)
{
	while (main->map->step < main->map->depth)
	{
		if (main->map->step == main->map->i)
		{
			ft_printf("for\n");
			if (main->map->bullet_direction == 'r')
				main->img->weapon->instances[main->map->w].x += 2 * main->map->len;
			if (main->map->bullet_direction == 'l')
				main->img->weapon->instances[main->map->w].x -= 2 * main->map->len;
			if (main->map->bullet_direction == 'u')
				main->img->weapon->instances[main->map->w].y -= 2 * main->map->len;
			if (main->map->bullet_direction == 'd')
				main->img->weapon->instances[main->map->w].y += 2 * main->map->len;
			main->map->i++;
		}
		ft_printf("%d\n", main->map->w);
			break ;
	}
	if (main->map->step == main->map->depth)
	{
		ft_printf("igual\n");
		main->img->weapon->instances[main->map->w].enabled = false;
		main->map->w++;
		main->map->firing = 0;
	}
}


void	ft_fire(t_main *main)
{
	ft_printf("firing - %d\n", main->map->firing);
	ft_printf("step %d\n", main->map->step);
	ft_printf("depth %d\n", main->map->depth);
	if (main->map->firing == 1)
	{
		if (main->map->depth - main->map->step == 3 && main->map->bullets == 1)
		{
			main->map->x_bullet = main->map->x_player;	
			main->map->y_bullet = main->map->y_player;	
			main->map->len_x_bullet = main->map->x_bullet * main->map->len;
			main->map->len_y_bullet = main->map->y_bullet * main->map->len;
			ft_printf("passou aquiiiiiiiiiiiii\n");
			if (mlx_image_to_window(main->mlx, main->img->weapon, main->map->len_x_bullet, main->map->len_y_bullet) < 0)
				return (ft_putstr_fd("Error\nPut image fails", 2));
			main->map->i = main->map->step;
			main->map->bullets = 0;
			main->map->bullet_direction = main->map->direction;
		}
		/*while (main->map->step < main->map->depth)
		{
			if (main->map->step == main->map->i)
			{
				ft_printf("for\n");
				if (main->map->bullet_direction == 'r')
					main->img->weapon->instances[main->map->w].x += 2 * main->map->len;
				if (main->map->bullet_direction == 'l')
					main->img->weapon->instances[main->map->w].x -= 2 * main->map->len;
				if (main->map->bullet_direction == 'u')
					main->img->weapon->instances[main->map->w].y -= 2 * main->map->len;
				if (main->map->bullet_direction == 'd')
					main->img->weapon->instances[main->map->w].y += 2 * main->map->len;
				main->map->i++;
			}
			ft_printf("%d\n", main->map->w);
			break ;
		}
		if (main->map->step == main->map->depth)
		{
			ft_printf("igual\n");
			main->img->weapon->instances[main->map->w].enabled = false;
			main->map->w++;
			main->map->firing = 0;
		}*/
		ft_shooting(main);
	}
	ft_printf("\n\n\n");
}

