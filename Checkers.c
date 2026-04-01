/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:25 by aalmoman          #+#    #+#             */
/*   Updated: 2026/04/01 23:21:16 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_reachable(t_game *game, char **map, int fd)
{
	int			i;
	int			j;
	t_player	start;

	start.x = game->player.x;
	start.y = game->player.y;
	check_path(map, position(start.x, start.y));
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
			{
				free_map(map);
				error_with_free(game, 0,
					"Error!\nisnt reachable target\n", fd);
			}
		}
	}
}

void	check_ber(t_game *game, char *arg, int fd)
{
	char	*t;

	t = arg;
	t += ft_strlen(arg) - 4;
	if (ft_strncmp(t, ".ber", 4))
	{
		close(fd);
		error_with_free(game, 0, "wrong extension\n", -1);
	}
}

void	init_info(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error!\n", 1);
		close(fd);
		free(game);
		exit(1);
	}
	check_ber(game, file, fd);
	check_map(game, fd, file);
	player_pos(game);
	game->collectibles = count_elements(game->map, 'C');
	cpy_map(game, fd);
	close(fd);
}

void	cpy_map(t_game *game, int fd)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (game->hight + 1));
	if (!map)
		error_with_free(game, 0, "Error!\n", fd);
	i = -1;
	while (game->map[++i])
	{
		map[i] = ft_strdup(game->map[i]);
		if (!map[i])
		{
			free_map(map);
			error_with_free(game, 0, "Error!\n", fd);
		}
	}
	map[i] = NULL;
	is_reachable(game, map, fd);
	free_map(map);
}
