/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:42:09 by ishenriq          #+#    #+#             */
/*   Updated: 2024/01/31 18:30:55 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "so_long.h"
# include "../lib/libft/gnl/get_next_line.h"

# define WIDTH 1920 
# define HEIGHT 1080
# define SIZE 130
# define EARTH "textures/earth.png"
# define MAPB "textures/mapb.png"
# define ROCK "textures/rock.png"
# define ROCKET "textures/rocket.png" 
# define COLLECT "textures/collectible.png"


typedef struct s_image
{
	mlx_image_t	*mapb;
	mlx_image_t	*earth;
	mlx_image_t	*rock;
	mlx_image_t	*rocket;
	mlx_image_t	*collect;
	mlx_texture_t	*mapb_tex;
	mlx_texture_t	*earth_tex;
	mlx_texture_t	*rock_tex;
	mlx_texture_t	*rocket_tex;
	mlx_texture_t	*collect_tex;
}	t_image;

typedef struct s_map
{
	int	nrow;
	int	ncol;
	int	nexit;
	int	nplayer;
	int	x_player;
	int	y_player;
	int	ncollect;
	char	*path_ber;
	char	**build_map;
	int	len_image;
}	t_map;

typedef struct s_game
{
	mlx_t	*mlx;
	void	*window;
	int	width;
	int	height;
	void	*id;
}	t_game;

typedef struct s_main
{
	t_image	*image;
	t_map	*map;
	t_game	*game;
}	t_main;



t_game	*init_game(void);
t_image	*init_image(void);
t_map	*init_map(void);
t_main	*init_main(void);

void	read_map(char **ber, t_map *map);
void	build_matrix_map(t_map *map);
void	put_image(t_game *game, t_map *map, t_image *image);
void	put_image_window(t_image *image, t_game *game, t_map *map);
void	construct_image_earth(t_game *game, t_image *image);
void	construct_image_mapb(t_game *game, t_image *image);
void	construct_image_rock(t_game *game, t_image *image);
void	construct_image_rocket(t_game *game, t_image *image);
void	construct_image_collect(t_game *game, t_image *image);
void ft_hook(mlx_key_data_t keydata, void* param);


#endif
