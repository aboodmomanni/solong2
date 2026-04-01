/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:49 by aalmoman          #+#    #+#             */
/*   Updated: 2026/04/01 23:20:47 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game, int fd, char *f_name)
{
	if (fd < 0)
		error_with_free(game, 0, "Error\n", -1);
	hight(game, f_name);
	game->map = (char **)malloc(sizeof(char *) * (game->hight + 1));
	if (!game->map)
		error_with_free(game, 0, "Error\n", -1);
	read_map_lines(game, fd);
	if (!validate(game->map))
		error_with_free(game, 0, "Error\n", fd);
}

void	load_symbol(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * SIZE, y * SIZE);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * SIZE, y * SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * SIZE, y * SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * SIZE, y * SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * SIZE, y * SIZE);
}

void	load_img(t_game *game, int h, int w)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"./textures/KOBE.xpm",
			&w, &h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/BASKET.xpm",
			&w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/RING.xpm", &w,
			&h);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/WALLS.xpm", &w,
			&h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/FLOOR.xpm", &w, &h);
}

void	load_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			load_symbol(game, y, x);
	}
}

int	set_mlx(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	load_img(game, h, w);
	if (!game->img.player || !game->img.collectible || !game->img.exit
		|| !game->img.wall || !game->img.floor)
	{
		ft_putstr_fd("Error!\n", 1);
		free_mlx(game, 0);
	}
	return (1);
}
