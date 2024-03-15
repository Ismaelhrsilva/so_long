/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:55:06 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/15 19:19:21 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

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
