/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:42:09 by ishenriq          #+#    #+#             */
/*   Updated: 2024/02/09 20:23:30 by ishenriq         ###   ########.fr       */
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
	int		n;
	int		x;
	int		y;
	char	type;
}	t_pos;

typedef struct s_img
{
	mlx_image_t	*mapb;
	mlx_image_t	*earth;
	mlx_image_t	*rock;
	mlx_image_t	*rocket;
	mlx_image_t	*collect;
}	t_img;

typedef struct s_map
{
	mlx_t	*mlx;
	int		nrow;
	int		ncol;
	int		nexit;
	int		nplayer;
	int		x_player;
	int		y_player;
	int		ncollect;
	char	*path_ber;
	char	**space;
	int		len;
	int		step;
	int		row_v;
}	t_map;

typedef struct s_main
{
	t_list	*list;
	t_img	*img;
	t_map	*map;
	mlx_t	*mlx;
}	t_main;

t_img		*init_img(void);
t_map		*init_map(void);
t_main		*init_main(void);
int			read_map(t_map *map);
int			build_matrix_map(t_map *map);
int			put_image(t_main *main);
int			put_image_window(t_main *main);
void		ft_hook(mlx_key_data_t keydata, void *param);
mlx_image_t	*construct_image(t_main *main, char *png, int type);
int			count_char(char *str, char c);
int			right_number_objects(t_main *main);
int			right_ber(t_main *main);
int			count_char_prohibited(t_map *map, char *str);
int			map_format(t_map *map, char *str);
int			ft_strlenspace(char *str);
int			valid_path(t_map *map);
void		ft_close(t_main *main);

#endif
