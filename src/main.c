/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/05 17:56:05 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_main	*main;
	int	len;

	if (argc != 2)
	{
		ft_printf("Number of arguments is incorrect");
		return (0);
	}
	main = init_main();
	main->map = init_map();
	main->img = init_img();
	main->list = NULL;
	main->map->path_ber = argv[1];
	if (right_ber(main))
		return (0);
	if (read_map(main->map))
		return (0);
	if (right_number_objects(main))
		return (0);
	len = main->map->len;
	main->mlx = mlx_init(len * main->map->ncol, len * main->map->nrow, "So_Long", true); 
	if (!main->mlx)
		return (0);
	put_image(main);
	//while (main->list)
	//{
	//	ft_printf("n: %c \n", ((t_pos *) main->list->content)->type);
	//	main->list = main->list->next; 
	//}
	mlx_key_hook(main->mlx, &ft_hook, main);
	mlx_loop(main->mlx);
	mlx_terminate(main->mlx);
	return (0);
}
