/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:53:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/05 19:58:19 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map.h"

t_game	*init_game(void)
{
	static t_game	game;
	return (&game);
}

t_map	*init_map(void)
{
	static t_map map;
	return (&map);
}
