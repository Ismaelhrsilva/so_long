/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:24:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/13 17:58:52 by ishenriq         ###   ########.fr       */
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

static int	position_validation_enemy(t_main *main, int isrow, int x, int y)
{
	int	signal;

	signal = -1;
	if (isrow % 2 == 0)
		signal = 1;

	if (isrow == 3 || isrow == 4)
	{
		if (main->map->space[y + signal][x] == '1')
		{
			ft_printf("Parede --> Vertical\n");
	  		return (1);
		}
		else
		{
			ft_printf("Não");
			return (0);
		}
	}
	else if (isrow == 1 || isrow == 2)
	{
		if (main->map->space[y][x + signal] == '1')
		{
			ft_printf("Parede\n");
			return (1);
		}
		else
		{
			ft_printf("Não");
			return (0);
		}
	}
	return (ft_printf("Aquiiiiii\n"));
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
		if (x > main->map->x_player && (type == 'A'))
		{
			if (!position_validation_enemy(main, 1, x, y))
			{	
				main->img->enemy->instances[n].x -= main->map->len;
				((t_pos *)aux->content)->x--;
			}
		}
		if (x < main->map->x_player && (type == 'A'))
		{
			if (!position_validation_enemy(main, 2, x, y))
			{
				main->img->enemy->instances[n].x += main->map->len;
				((t_pos *)aux->content)->x++;
			}
		}
		if (y > main->map->y_player && (type == 'A'))
		{
			if (!position_validation_enemy(main, 3, x, y))
			{
				main->img->enemy->instances[n].y -= main->map->len;
				((t_pos *)aux->content)->y--;
			}
		}
		if (y < main->map->y_player && (type == 'A'))
		{
			if (!position_validation_enemy(main, 4, x, y))
			{
				main->img->enemy->instances[n].y += main->map->len;
				((t_pos *)aux->content)->y++;
			}
		}
		aux = aux->next;
	}
}
