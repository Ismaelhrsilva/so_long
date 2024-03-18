/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/18 18:30:19 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static void	pos_obj(t_list **list, int col, int row, char type)
{
	t_pos	*pos;
	int		n;
	t_list	*aux;

	aux = *list;
	n = 0;
	pos = malloc(sizeof(t_pos));
	if (pos == NULL)
		return ;
	while (aux)
	{
		if (type == ((t_pos *)aux->content)->type)
			n++;
		aux = aux->next;
	}
	pos->n = n;
	pos->type = type;
	pos->x = col;
	pos->y = row;
	ft_lstadd_back(list, ft_lstnew(pos));
}

static int	ft_switch(int r, int c, int l, t_main *main)
{
	int	h;

	h = r * l;
	if (main->map->space[r][c] == '1')
		if (mlx_image_to_window(main->mlx, main->img->rock, c * l, h) < 0)
			return (ft_putstr_fd("Error\nPut image fails", 2), 1);
	if (main->map->space[r][c] == 'C')
		if (mlx_image_to_window(main->mlx, main->img->collect, c * l, h) < 0)
			return (ft_putstr_fd("Error\nPut image fails", 2), 1);
	if (main->map->space[r][c] == 'E')
	{
		if (mlx_image_to_window(main->mlx, main->img->earth, c * l, h) < 0)
			return (ft_putstr_fd("Error\nPut image fails", 2), 1);
		main->img->earth->instances[0].enabled = false;
		if (mlx_image_to_window(main->mlx, main->img->earth_f, c * l, h) < 0)
			return (ft_putstr_fd("Error\nPut image fails", 2), 1);
		main->img->earth_f->instances[0].enabled = false;
	}
	if (main->map->space[r][c] == 'A')
	{
		if (mlx_image_to_window(main->mlx, main->img->enemy, c * l, h) < 0)
			return (ft_putstr_fd("Error\nPut image fails", 2), 1);
	}
	pos_obj(&main->list, c, r, main->map->space[r][c]);
	return (0);
}

static int	whiling(int row, int col, int len, t_main *main)
{
	mlx_image_to_window(main->mlx, main->img->mapb, 0, 0);
	while (row < main->map->nrow)
	{
		col = 0;
		while (col < main->map->ncol)
		{
			if (ft_switch(row, col, len, main))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int	put_image_window(t_main *main)
{
	int		row;
	int		col;
	int		len;

	col = 0;
	row = 0;
	len = main->map->len;
	if (whiling(row, col, len, main))
		return (1);
	if ((mlx_image_to_window(main->mlx, main->img->rocket,
				main->map->x_player * len, main->map->y_player * len) < 0)
		|| (mlx_image_to_window(main->mlx, main->img->rocket_up,
				main->map->x_player * len, main->map->y_player * len) < 0)
		|| (mlx_image_to_window(main->mlx, main->img->rocket_down,
				main->map->x_player * len, main->map->y_player * len) < 0)
		|| (mlx_image_to_window(main->mlx, main->img->rocket_left,
				main->map->x_player * len, main->map->y_player * len) < 0)
		|| (mlx_image_to_window(main->mlx, main->img->write, 0, 0) < 0))
		return (ft_putstr_fd("Error\nPut image fails", 2), 1);
	main->img->rocket_up->instances[0].enabled = false;
	main->img->rocket_down->instances[0].enabled = false;
	main->img->rocket_left->instances[0].enabled = false;
	return (0);
}

int	put_image(t_main *main)
{
	main->img->earth = construct_image(main, EARTH, 1);
	main->img->earth_f = construct_image(main, EARTH_F, 1);
	main->img->rock = construct_image(main, ROCK, 1);
	main->img->rocket = construct_image(main, ROCKET, 1);
	main->img->rocket_up = construct_image(main, ROCKET_UP, 1);
	main->img->rocket_down = construct_image(main, ROCKET_DOWN, 1);
	main->img->rocket_left = construct_image(main, ROCKET_LEFT, 1);
	main->img->collect = construct_image(main, COLLECT, 1);
	main->img->enemy = construct_image(main, ENEMY, 1);
	main->img->weapon = construct_image(main, WEAPON, 1);
	main->img->write = construct_write(main, WRITE);
	main->img->mapb = construct_image(main, MAPB, 0);
	if (!main->img->earth || !main->img->earth_f || !main->img->rock
		|| !main->img->rocket || !main->img->rocket_up
		|| !main->img->rocket_down || !main->img->rocket_left
		|| !main->img->collect || !main->img->mapb
		|| !main->img->enemy || !main->img->write
		|| put_image_window(main))
		return (1);
	else
		return (0);
}
