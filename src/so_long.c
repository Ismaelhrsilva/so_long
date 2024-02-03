/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:42 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/03 10:41:54 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pos_obj(t_list **list, int col, int row, char *type)
{
	t_pos	*pos;
	int	n;
	t_list *aux;

	aux = *list;
	pos = malloc(sizeof(t_pos));
	n = 0;
	if (pos == NULL)
		return ;
	while (aux)
		if (!ft_memcmp(type, ((t_pos *)aux->content)->type, 1))
			n++;
	pos->n = n;
	pos->type = type;
	pos->x = col;
	pos->y = row;
	ft_lstadd_back(list, ft_lstnew(pos));
}



void	put_image_window(t_image *image, t_game	*game, t_map *map, t_list **list)
{
	int	row;
	int	col;
	int	len;
	int	n_collect;
	t_pos	*pos;

	n_collect = 0;
	row = 0;
	len = map->len_image;
	mlx_image_to_window(game->mlx, image->mapb, 0, 0);
	while (row < map->nrow)
	{
		col = 0;
		while (col < map->ncol)
		{
			if (map->build_map[row][col] == '1')
				mlx_image_to_window(game->mlx, image->rock, col * map->len_image , row * map->len_image);
			if (map->build_map[row][col] == 'C')
			{
				mlx_image_to_window(game->mlx, image->collect, col * map->len_image , row * map->len_image);
				pos = malloc(sizeof(t_pos));
				pos_obj(list, col, row, &map->build_map[row][col]);
//				if (pos == NULL)
//					return ;
//				pos->n = n_collect++;
//				pos->type = "C";
//				pos->x = col;
//				pos->y = row;
//				ft_lstadd_back(list, ft_lstnew(pos));
			}
			if (map->build_map[row][col] == 'E')
				mlx_image_to_window(game->mlx, image->earth, col * map->len_image , row * map->len_image);
			if (map->build_map[row][col] == 'P')
			{	
				map->x_player = col;
				map->y_player = row;
			}
			col++;
		}
		row++;
	}
	mlx_image_to_window(game->mlx, image->rocket, map->x_player * map->len_image , map->y_player * map->len_image);
	image->rock->instances[4].enabled = false;
}

void	put_image(t_game *game, t_map *map, t_image *image, t_list **list)
{
	construct_image_earth(game, image, map);
	construct_image_mapb(game, image);
	construct_image_rock(game, image, map);
	construct_image_rocket(game, image, map);
	construct_image_collect(game, image, map);
	put_image_window(image, game, map, list);
}

int	main(int argc, char **argv)
{
	t_main	*main;
	int	len;

	if (argc != 2)
		return (0);
	main = init_main();

	main->map = init_map();
	main->game = init_game();
	main->image = init_image();
	main->list = NULL;
	main->map->path_ber = argv[1];
	read_map(&argv[1], main->map);
	len = main->map->len_image;
	main->game->mlx = mlx_init(len * main->map->ncol, len * main->map->nrow, "So_Long", true); 
	if (!main->game->mlx)
		return (0);
	put_image(main->game, main->map, main->image, &main->list);
	/*while (main->list)
	{
		ft_printf("n: %d \n", ((t_pos *) main->list->content)->n);
		main->list = main->list->next; 
	}*/
	mlx_key_hook(main->game->mlx, &ft_hook, main);
	mlx_loop(main->game->mlx);
	mlx_terminate(main->game->mlx);
	return (0);
}
