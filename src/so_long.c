/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/04 17:03:28 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pos_obj(t_list **list, int col, int row, char type)
{
	t_pos	*pos;
	int	n;
	t_list *aux;

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

void	put_image_window(t_main *main)
{
	int	row;
	int	col;
	int	len;
	int	n_collect;
	t_pos	*pos;

	n_collect = 0;
	row = 0;
	len = main->map->len;
	mlx_image_to_window(main->mlx, main->img->mapb, 0, 0);
	while (row < main->map->nrow)
	{
		col = 0;
		while (col < main->map->ncol)
		{
			if (main->map->space[row][col] == '1')
				mlx_image_to_window(main->mlx, main->img->rock, col * len , row * len);
			if (main->map->space[row][col] == 'C')
			{
				mlx_image_to_window(main->mlx, main->img->collect, col * len, row * len);
				pos_obj(&main->list, col, row, main->map->space[row][col]);
			}
			if (main->map->space[row][col] == 'E')
			{	
				mlx_image_to_window(main->mlx, main->img->earth, col * len , row * len);
				main->img->earth->instances[0].enabled = false;
				pos_obj(&main->list, col, row, main->map->space[row][col]);
			}
			if (main->map->space[row][col] == 'P')
			{	
				main->map->x_player = col;
				main->map->y_player = row;
			}
			col++;
		}
		row++;
	}
	mlx_image_to_window(main->mlx, main->img->rocket, main->map->x_player * len, main->map->y_player * len);
}

void	put_image(t_main *main)
{
	main->img->earth = construct_image(main, EARTH, 1);
	main->img-> rock = construct_image(main,ROCK, 1);
	main->img->rocket = construct_image(main, ROCKET, 1);
	main->img->collect = construct_image(main, COLLECT, 1);
	main->img->mapb = construct_image(main, MAPB, 0);
	put_image_window(main);
}
