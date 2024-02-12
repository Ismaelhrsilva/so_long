/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/12 17:23:18 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_main	*main;

	if (argc != 2)
		return (ft_putstr_fd("Error\nNumber of args are incorrect", 2), 2);
	main = init_main();
	main->map = init_map();
	main->img = init_img();
	main->list = NULL;
	main->map->path_ber = argv[1];
	if (right_ber(main))
		return (ft_close(main), 0);
	if (read_map(main->map))
		return (ft_close(main), 0);
	main->mlx = mlx_init(main->map->len * main->map->ncol,
			main->map->len * main->map->nrow, "So_Long", true);
	if (!main->mlx)
		return (ft_close(main), ft_putstr_fd("Error\nMLX fails", 2), 2);
	if (put_image(main))
		return (ft_close(main), 0);
	mlx_key_hook(main->mlx, &ft_hook, main);
	mlx_loop_hook(main->mlx, &ft_loop, main);
	mlx_loop(main->mlx);
	mlx_terminate(main->mlx);
	return (ft_close(main), 0);
}
