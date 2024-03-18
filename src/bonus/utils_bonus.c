/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:59:20 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/18 18:03:56 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

int	ft_strlenspace(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str && str[i] != '\n')
	{
		len++;
		i++;
	}
	return (len);
}

int	count_char(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	count_char_prohibited(t_map *map, char *str)
{
	int	wall;
	int	back;
	int	exit;
	int	total_c;
	int	allow_c;

	total_c = map->ncol;
	wall = count_char(str, '1');
	back = count_char(str, '0');
	exit = count_char(str, 'E') + count_char(str, 'A');
	allow_c = count_char(str, 'P') + count_char(str, 'C') + exit + wall + back;
	if (total_c != allow_c)
	{
		ft_putstr_fd("Error\nLetter prohibited", 2);
		return (1);
	}
	else
		return (0);
}

void	ft_exit(t_main *main, int x, int y)
{
	int				x_col;
	int				y_col;
	char			type;
	static t_list	*aux;

	x_col = 0;
	y_col = 0;
	type = '\0';
	aux = main->list;
	if (main->map->ncollect == -1)
	{
		while (aux)
		{
			x_col = ((t_pos *)aux->content)->x;
			y_col = ((t_pos *)aux->content)->y;
			type = ((t_pos *)aux->content)->type;
			if (x == x_col && y == y_col && (type == 'E'))
				mlx_close_window(main->mlx);
			aux = aux->next;
		}
	}
}

void	is_collectable(t_main *main, int x, int y)
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
