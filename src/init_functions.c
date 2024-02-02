/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:53:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/02 18:48:56 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(void)
{
	static t_game	game;
	return (&game);
}

t_map	*init_map(void)
{
	static t_map	map;
	return (&map);
}

t_image	*init_image(void)
{
	static t_image	image;
	return (&image);
}

//t_pos	*init_pos(void)
//{
//	static t_pos	pos;
//	return (&pos);
//}

t_main	*init_main(void)
{
	static t_main	main;
	return (&main);
}
