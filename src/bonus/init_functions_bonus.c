/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:53:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/11 14:13:22 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

t_map	*init_map(void)
{
	static t_map	map;

	return (&map);
}

t_img	*init_img(void)
{
	static t_img	img;

	return (&img);
}

t_main	*init_main(void)
{
	static t_main	main;

	return (&main);
}
