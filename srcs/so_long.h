/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:57 by aalmoman          #+#    #+#             */
/*   Updated: 2026/03/21 12:26:30 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define SIZE		48
# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100
# define UP			65362
# define LEFT		65361
# define DOWN		65364
# define RIGHT		65363

typedef struct s_pos
{
	int	col;
	int	row;
}	t_pos;

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

typedef struct s_game
{
	int			on_exit;
	int			moves;
	void		*win;
	char		**map;
	int			hight;
	int			width;
	t_player	player;
	int			collectibles;
	void		*exit_img;
	void		*wall_img;
	void		*player_img;
	void		*collect_img;
	void		*background_img;
	void		*mlx;
}			t_game;

void		null_end(char *line);
void		load_map(t_game *game);
int			free_mlx(t_game *game, int code);
void		error_with_free(t_game *game, int code, char *text, int fd);
void		find_player(t_game *game);
void		free_map(char **map);
void		get_height(t_game *game, char *f_name);
void		is_reachable(t_game *game, char **map, int fd);
void		render_tiles(t_game *game, int y, int x);
void		check_map(t_game *game, int fd, char *f_name);
int			validate(char **map);
void		load_img(t_game *game, int h, int w);
void		get_map(char **map, int pos, char *line, t_game *game);
void		check_extension(t_game *game, char *str);
void		init_info(char *f_name, t_game *game);
int			initialize_game(t_game *game);
void		cpy_map(t_game *game, int fd);
int			key_press(int keycode, t_game *game);
int			movement(t_game *game, int x, int y);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			end_game(t_game *game);
void		check_path(char **map, t_pos tile);
t_pos		position(int col, int row);
void		read_map_lines(t_game *game, int fd);
int			count_elements(char **map, char c);

#endif