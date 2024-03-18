/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:24:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/18 17:57:39 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static int	ft_aux_walk_enemy_right(t_main *main, int x, int y, int n)
{
	if (x > main->map->x_player
		&& !position_validation_enemy(main, x - 1, y))
	{
		main->img->enemy->instances[n].x -= main->map->len;
		return (1);
	}
	return (0);
}

static int	ft_aux_walk_enemy_left(t_main *main, int x, int y, int n)
{
	if (x < main->map->x_player
		&& !position_validation_enemy(main, x + 1, y))
	{
			main->img->enemy->instances[n].x += main->map->len;
		return (1);
	}
	return (0);
}

static int	ft_aux_walk_enemy_down(t_main *main, int x, int y, int n)
{
	if (y > main->map->y_player
		&& !position_validation_enemy(main, x, y - 1))
	{
		main->img->enemy->instances[n].y -= main->map->len;
		return (1);
	}
	return (0);
}

static int	ft_aux_walk_enemy_up(t_main *main, int x, int y, int n)
{
	if (y < main->map->y_player
		&& !position_validation_enemy(main, x, y + 1))
	{
			main->img->enemy->instances[n].y += main->map->len;
		return (1);
	}
	return (0);
}

void	walk_enemy(t_main *main)
{
	char	type;
	int		n;
	t_list	*aux;

	aux = main->list;
	while (aux)
	{
		type = ((t_pos *)aux->content)->type;
		n = ((t_pos *)aux->content)->n;
		if (type == 'A' && ft_aux_walk_enemy_right(main,
				((t_pos *)aux->content)->x, ((t_pos *)aux->content)->y, n))
			((t_pos *)aux->content)->x--;
		if (type == 'A' && ft_aux_walk_enemy_left(main,
				((t_pos *)aux->content)->x, ((t_pos *)aux->content)->y, n))
			((t_pos *)aux->content)->x++;
		if (type == 'A' && ft_aux_walk_enemy_down(main,
				((t_pos *)aux->content)->x, ((t_pos *)aux->content)->y, n))
			((t_pos *)aux->content)->y--;
		if (type == 'A' && ft_aux_walk_enemy_up(main,
				((t_pos *)aux->content)->x, ((t_pos *)aux->content)->y, n))
			((t_pos *)aux->content)->y++;
		aux = aux->next;
	}
}
