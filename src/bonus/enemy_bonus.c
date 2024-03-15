/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:24:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/15 18:26:34 by ishenriq         ###   ########.fr       */
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


static int	position_validation_enemy(t_main *main,  int x, int y)
{
	ft_printf("coluna -- %d\n", x);
	ft_printf("linha -- %d\n", y);
	if (main->map->space[y][x] == '1')
	{
		//ft_printf("%c\n", main->map->space[y][x]);
		return (1);
	}
	else
	{
		main->map->walking = 1;
		return (0);
	}
}


void	walk_enemy(t_main *main)
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
		main->map->walking = 0;
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

