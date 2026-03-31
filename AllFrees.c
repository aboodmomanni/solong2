/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllFrees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:17 by aalmoman          #+#    #+#             */
/*   Updated: 2026/03/21 11:37:06 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_mlx(t_game *game, int code)
{
	free_map(game->map);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	if (!code)
		exit(1);
	exit(0);
}

void	free_map(char **s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	error_with_free(t_game *game, int code, char *s, int fd)
{
	ft_putstr_fd(s, 1);
	if (game)
	{
		free_map(game->map);
		free(game);
	}
	if (fd >= 0)
		close(fd);
	if (!code)
		exit(1);
	exit(0);
}
