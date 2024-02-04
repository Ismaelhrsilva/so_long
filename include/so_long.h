/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:42:09 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/04 15:24:06 by ishenriq         ###   ########.org.br   */
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
# define HEIGHT 960
# define EARTH "textures/earth.png"
# define MAPB "textures/mapb.png"
# define ROCK "textures/rock.png"
# define ROCKET "textures/rocket.png" 
# define COLLECT "textures/collectible.png"


typedef struct s_pos
{
	int	n;
	int	x;
	int	y;
	char	type;
}	t_pos;

typedef struct s_img
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
}	t_img;

typedef struct s_map
{
	mlx_t	*mlx;
	int	nrow;
	int	ncol;
	int	nexit;
	int	nplayer;
	int	x_player;
	int	y_player;
	int	ncollect;
	char	*path_ber;
	char	**space;
	int	len;
	int	step;
}	t_map;

typedef struct s_main
{
	t_list	*list;
	t_img	*img;
	t_map	*map;
	mlx_t	*mlx;
}	t_main;


t_img	*init_img(void);
t_map	*init_map(void);
t_main	*init_main(void);

void	read_map(char **ber, t_map *map);
void	build_matrix_map(t_map *map);
void	put_image(t_main *main);
void	put_image_window(t_main *main);
void	construct_image_earth(t_main *main);
void	construct_image_mapb(t_main *main);
void	construct_image_rock(t_main *main);
void	construct_image_rocket(t_main *main);
void	construct_image_collect(t_main *main);
void	ft_hook(mlx_key_data_t keydata, void* param);

#endif
