/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:03:03 by aalmoman          #+#    #+#             */
/*   Updated: 2026/04/01 00:19:19 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hight(t_game *game, char *infile)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(infile, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->hight = i;
	free(line);
	close(fd);
}

void	player_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->width = ft_strlen(game->map[0]);
	game->moves = 0;
	while (y < game->hight)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

int	count_elements(char **map, char c)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == c)
				count++;
	}
	return (count);
}
