/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:05:06 by orfreoua          #+#    #+#             */
/*   Updated: 2021/10/26 11:58:27 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define    SUCCESS     1
# define    FAIL        0
# define    BUFFER_SIZE 10

/*
** Printf colors
*/

# define RED			"\033[00;31m"
# define BLUE_LIGHT		"\033[01;34m"
# define BLUE			"\033[00;34m"
# define NORMAL			"\033[00m"

/*
** Key
*/

# define ESC    		65307
# define A      		97
# define W      		119
# define D      		100
# define S      		115

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct s_screen
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_screen;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	char		**map;
	int			grid_width;
	int			grid_height;
}				t_map;

typedef struct s_player
{
	t_screen	right1;
	t_screen	right2;
	t_screen	right3;
	t_point		pos;
	int			nb_p;
}				t_player;

typedef struct s_collectible
{
	int			nb_c;
	t_screen	screen_c;
}				t_collectible;

typedef struct s_exit
{
	int			nb_e;
	t_screen	screen_e;
}				t_exit;

typedef struct s_draw
{
	int			x;
	int			y;
	float		r_x;
	float		r_y;
	int			color;
	int			pos_x;
	int			pos_y;
	int			p_data_x;
	int			p_data_y;
}				t_draw;

typedef struct s_bonus
{
	t_screen	oursin;
	t_point		pos;
	t_point		pos2;
	short		dir;
	short		dir2;
	short		on;
}				t_bonus;

typedef struct s_data
{
	t_map			map;
	t_player		player;
	t_collectible	collectible;
	t_exit			exit;
	t_screen		mlx;
	t_screen		floor;
	t_screen		wall;
	int				time;
	int				shiffting;
	char			*moves_ascii;
	t_bonus			bonus;
}				t_data;

/*
**  main.c
*/
void			init_data(t_data *data);
void			so_long_loop(t_data *data);
void			load_game(t_data *data);
/*
** Load_map.c
*/
int				load_map(t_data *data, void *file);
int				good_map(t_data *data);
int				check_name(char *file);
int				check_map(t_data *data, int x, int y);
/*
** F_libft
*/
void			ft_free(char *s);
size_t			ft_strlen(const char *s);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*join_str(char const *s1, char const *s2);
int				has_return(char *str);
/*
**  Read.c
*/
int				get_next_line(int fd, char **line, int reader);
int				fill_map(t_data *data, void *file, int ret, int i);
char			*get_save(char *save);
char			*get_line(char *str);
/*
**  Free.c
*/
void			free_tab_two_d(char **tab);
int				free_all(t_data *data);
void			close_windows(t_data *data);
void			free_map_two_d_with_limit(char **map, int limit);
void			destroy_textures(t_data *data);
/*
** load_img.c
*/
void			init_textures(t_data *data);
t_screen		load_image(void *mlx, char *path, t_data *data);
/*
** game.c
*/
int				update(t_data *data);
int				key_hook(int key, t_data *data);
int				is_collectible(t_data *data, int x, int y);
/*
** draw.c
*/
void			my_mlx_pixel_put(t_screen *screen, int x, int y, int color);
void			set_pixel(t_screen *screen, int x, int y, int color);
int				get_pixel(t_screen *img, int x, int y);
/*
** draw_map.c
*/
void			draw_player(t_data *data);
void			draw_map(t_data *data);
void			draw_on_img(t_screen *img, t_screen *s_img, int startX,
					int startY);
void			draw_next(t_data *data);
/*
** ft_itoa.c
*/
char			*ft_itoa(unsigned long long nb);
int				len(unsigned long long nb);
/*
** utils.c
*/
int				error(int return_vallue, char *msg);
int				size_of_map(void *file);
int				find_index(char c, char *index_tab);
/*
** bonus.c
*/
void			display_nb_moves(t_data *data);
void			bonus(t_data *data);
void			bonus_display(t_data *data);
void			moves_ia(t_data *data);
void			moves_ia2(t_data *data);

#endif
