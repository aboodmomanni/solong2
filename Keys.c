/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:34 by aalmoman          #+#    #+#             */
/*   Updated: 2026/03/25 16:45:15 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_move(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
		game->player.x * SIZE, game->player.y * SIZE);
	if (game->collectibles
		&& game->map[game->player.y][game->player.x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			game->player.x * SIZE, game->player.y * SIZE);
	}
	game->player.x = new_x;
	game->player.y = new_y;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.player, new_x * SIZE, new_y * SIZE);
	game->moves++;
	ft_putstr_fd("Moves :", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

int	movement(t_game *game, int x, int y)
{
	int	newx;
	int	newy;

	newx = game->player.x + x;
	newy = game->player.y + y;
	if (game->map[newy][newx] != '1')
	{
		new_move(game, newx, newy);
		if (game->map[newy][newx] == 'E' && !game->collectibles)
		{
			ft_putstr_fd("we did it :", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putstr_fd("\n", 1);
			free_mlx(game, 1);
			return (0);
		}
	}
	if (game->map[newy][newx] == 'C' && game->collectibles > 0)
	{
		game->map[newy][newx] = '0';
		game->collectibles--;
	}
	return (1);
}

int	key_press(int k, t_game *game)
{
	if (k == ESC)
		return (end_game(game));
	else if (k == W || k == UP)
		move_up(game);
	else if (k == A || k == LEFT)
		move_left(game);
	else if (k == D || k == RIGHT)
		move_right(game);
	else if (k == S || k == DOWN)
		move_down(game);
	return (0);
}
