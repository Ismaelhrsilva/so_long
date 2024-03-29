/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:53:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/11 09:23:23 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/so_long.h"

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
