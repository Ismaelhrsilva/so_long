/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/05 20:27:44 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map.h"

/*static void ft_hook(void* param)
{
	const mlx_t* mlx = param;
	int	i;

	i = 0;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	while (i < 3)
		i++;
	return ;
}
*/
int	main(int argc, char **argv)
{
	mlx_t*	mlx;
	mlx_image_t*	img;
	t_map	*map;

	if (argc != 2)
		return (0);
	map = init_map();
	read_map(&argv[1], map);
	mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!mlx)
		return (0);
	
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (0);

	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
