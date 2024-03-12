/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:24:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/12 20:36:07 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

void	is_enemy(t_main *main, int x, int y)
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
		if (x == x_col && y == y_col && (type == 'A'))
		{
			mlx_close_window(main->mlx);
		}
		aux = aux->next;
	}
}


/*static int	position_validation_enemy(t_main *main, int x, int y)
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
}*/

void	walk_enemy(t_main *main)
{
	int		x;
	int		y;
	char	type;
	int		n;
	t_list	*aux;

	aux = main->list;
	while (aux)
	{
		x = ((t_pos *)aux->content)->x;
		y = ((t_pos *)aux->content)->y;
		type = ((t_pos *)aux->content)->type;
		n = ((t_pos *)aux->content)->n;
		if (x > main->map->x_player && (type == 'A'))
		{
			main->img->enemy->instances[n].x -= main->map->len;
			((t_pos *)aux->content)->x--;
		}
		if (x < main->map->x_player && (type == 'A'))
		{
			main->img->enemy->instances[n].x += main->map->len;
			((t_pos *)aux->content)->x++;
		}
		if (y > main->map->y_player && (type == 'A'))
		{
			main->img->enemy->instances[n].y -= main->map->len;
			((t_pos *)aux->content)->y--;
		}
		if (y < main->map->y_player && (type == 'A'))
		{
			main->img->enemy->instances[n].y += main->map->len;
			((t_pos *)aux->content)->y++;
		}
		aux = aux->next;
	}
}
