/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:26:44 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/15 20:59:13 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

static void	ft_fire(t_main *main)
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
	ft_printf("\n\n\n");
}

static void	is_collectable(t_main *main, int x, int y)
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
		if (x == x_col && y == y_col && (type == 'C'))
		{
			if (main->img->collect->instances[n].enabled == true)
			{
				main->img->collect->instances[n].enabled = false;
				main->map->ncollect--;
				if (main->map->ncollect == 0)
					main->map->ncollect = -1;
			}
		}
		aux = aux->next;
	}
}

static int	position_validation(t_main *main, int x, int y)
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
}

static void	player_image(t_main *main, int x, int y)
{
	
	main->img->rocket->instances[0].enabled = false;
	main->img->rocket_up->instances[0].enabled = false;
	main->img->rocket_down->instances[0].enabled = false;
	main->img->rocket_left->instances[0].enabled = false;
	if (x == 0 && y < 0)
	{
		main->map->direction = 'u';
		main->img->rocket_up->instances[0].enabled = true;
	}
	if (x == 0 && y > 0)
	{
		main->map->direction = 'd';
		main->img->rocket_down->instances[0].enabled = true;

	}
	if (x < 0 && y == 0)
	{
		main->map->direction = 'l';
		main->img->rocket_left->instances[0].enabled = true;
	}
	if (x > 0 && y == 0)
	{
		main->map->direction = 'r';
		main->img->rocket->instances[0].enabled = true;
	}
	main->img->rocket->instances[0].y += y;
	main->img->rocket->instances[0].x += x;
	main->img->rocket_up->instances[0].y += y;
	main->img->rocket_up->instances[0].x += x;
	main->img->rocket_down->instances[0].y += y;
	main->img->rocket_down->instances[0].x += x;
	main->img->rocket_left->instances[0].y += y;
	main->img->rocket_left->instances[0].x += x;
}



static void	step(t_main *main, int x, int y)
{
	char	*number;
	char	*join;

	if (position_validation(main, x, y))
	{
		is_collectable(main, main->map->x_player, main->map->y_player);
		walk_enemy(main);
		is_enemy(main, main->map->x_player, main->map->y_player);
		ft_exit(main, main->map->x_player, main->map->y_player);
		
		player_image(main, x, y);
		main->map->step++;
		ft_fire(main);
		if (main->img->write_text)
			mlx_delete_image(main->mlx, main->img->write_text);
		number = ft_itoa(main->map->step);
		join = ft_strjoin("Number of movements ", number);
		main->img->write_text = mlx_put_string(main->mlx, join, 0, 0);
		if (!main->img->write_text)
			return ;
		if (mlx_resize_image(main->img->write_text, main->map->len * 2,
				main->map->len / 3) == 0)
			return ;
		free(number);
		free(join);
	}
}


void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_main	*main;
	int		len;

	main = (t_main *) param;
	len = main->map->len;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(main->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		step(main, 0, -len);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		step(main, 0, len);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		step(main, -len, 0);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		step(main, len, 0);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		if (main->map->firing == 0)
		{
			main->map->depth = main->map->step + 3;
			main->map->firing = 1;
			main->map->bullets = 1;
		}
		ft_fire(main);
	}
}
