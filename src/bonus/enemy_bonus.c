/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:24:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/15 21:45:02 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

void	is_enemy(t_main *main, int x, int y)
{
	int		x_col;
	int		y_col;
	char	type;
	int		n;
	int		died;
	t_list	*aux;

	aux = main->list;
	while (aux)
	{
		x_col = ((t_pos *)aux->content)->x;
		y_col = ((t_pos *)aux->content)->y;
		type = ((t_pos *)aux->content)->type;
		n = ((t_pos *)aux->content)->n;
		died = ((t_pos *)aux->content)->died;
		if (x == x_col && y == y_col && (type == 'A') && died != 1)
		{
			mlx_close_window(main->mlx);
		}
		aux = aux->next;
	}
}

void	enemy_dies(t_main *main)
{
	int		x_col;
	int		y_col;
	char	type;
	int		n;
	t_list	*aux;

	aux = main->list;
	while (aux)
	{
		x_col = ((t_pos *)aux->content)->x;
		y_col = ((t_pos *)aux->content)->y;
		type = ((t_pos *)aux->content)->type;
		n = ((t_pos *)aux->content)->n;
		if (main->map->x_bullet == x_col && main->map->y_bullet == y_col && (type == 'A'))
		{
			main->img->enemy->instances[n].enabled = false;
			((t_pos *)aux->content)->n = 'a';
			main->aux_died = main->list;
			while (main->aux_died)
			{
				if (((t_pos *)main->aux_died->content)->n == n && ((t_pos *)main->aux_died->content)->type == 'a')
					((t_pos *)main->aux_died->content)->died = 1;
				main->aux_died = main->aux_died->next;
			}
		}
		aux = aux->next;
	}
}

static int	position_validation_enemy(t_main *main,  int x, int y)
{
	if (main->map->space[y][x] == '1')
		return (1);
	else
		return (0);
}


void	walk_enemy(t_main *main)
{
	int		x;
	int		y;
	char	type;
	int		n;
	t_list	*aux;

	if (main->map->step % 2)
		return ;
	aux = main->list;
	while (aux)
	{
		x = ((t_pos *)aux->content)->x;
		y = ((t_pos *)aux->content)->y;
		type = ((t_pos *)aux->content)->type;
		n = ((t_pos *)aux->content)->n;
		if (type == 'A' && ((t_pos *)aux->content)->died != 1)
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

