/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2023/12/16 19:51:12 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map.h"

int	main(int argc, char **argv)
{
	mlx_t*	mlx;
	t_map*	map;
	char	**game_map;

	game_map = construct_map(argc, argv, &map);
	init_game(game_map, map);
	return (0);

	//if (!(mlx = mlx_init(WIDTH,HEIGHT, "so_long", true)))
	//	return (0);
	//mlx_loop(mlx);
	//mlx_terminate(mlx);
}
