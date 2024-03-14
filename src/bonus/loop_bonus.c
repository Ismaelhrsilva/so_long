/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:55:06 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/13 21:16:01 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static void	ft_weapon(t_main *main)
{
	
	int		x;
	int		y;
	char	type;
	int		n;
	t_list	*aux;

	//if (main->map->step % 2)
	//	return ;
	aux = main->list;
	while (aux)
	{
		x = ((t_pos *)aux->content)->x;
		y = ((t_pos *)aux->content)->y;
		type = ((t_pos *)aux->content)->type;
		n = ((t_pos *)aux->content)->n;
		if (type == 'A')
		{
			if (x > main->map->x_player)
			{
				if (!position_validation_enemy(main, x - 1, y))
				{	
					main->img->enemy->instances[n].x -= main->map->len;
					((t_pos *)aux->content)->x--;
					x--;
				}
			}
			if (x < main->map->x_player)
			{
				if (!position_validation_enemy(main, x + 1, y))
				{
					main->img->enemy->instances[n].x += main->map->len;
					((t_pos *)aux->content)->x++;
					x++;
				}
			}
			if (y > main->map->y_player)
			{
				if (!position_validation_enemy(main, x, y - 1))
				{
					main->img->enemy->instances[n].y -= main->map->len;
					((t_pos *)aux->content)->y--;
					y--;
				}
			}
			if (y < main->map->y_player)
			{
				if (!position_validation_enemy(main, x, y + 1))
				{
					main->img->enemy->instances[n].y += main->map->len;
					((t_pos *)aux->content)->y++;
					y++;
				}
			}
		}
		aux = aux->next;
	}
}



void	ft_loop(void *v)
{
	t_main	*main;
	int		time;

	time = (int )mlx_get_time();
	main = (t_main *) v;
	if (main->map->ncollect == -1)
	{
		if (time % 2 == 0)
		{
			main->img->earth->instances[0].enabled = false;
			main->img->earth_f->instances[0].enabled = true;
		}
		if (time % 2 == 1)
		{
			main->img->earth->instances[0].enabled = true;
			main->img->earth_f->instances[0].enabled = false;
		}
	}
}
