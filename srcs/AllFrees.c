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
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->background_img)
		mlx_destroy_image(game->mlx, game->background_img);
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
