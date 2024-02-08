/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/07 20:50:04 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*construct_image(t_main *main, char *png, int type)
{
	mlx_texture_t	*temp;
	mlx_image_t		*image;
	int				len_w;
	int				len_h;

	if (type == 1)
	{
		len_w = main->map->len;
		len_h = main->map->len;
	}
	else
	{
		len_w = WIDTH;
		len_h = HEIGHT;
	}
	temp = mlx_load_png(png);
	if (!temp)
		return (ft_printf("Error\nIt isn't possible to build texture"), NULL);
	image = mlx_texture_to_image(main->mlx, temp);
	if (!image)
		return (ft_printf("Error\nIt isn't possible to build image"), NULL);
	mlx_resize_image(image, len_w, len_h);
	return (image);
}
