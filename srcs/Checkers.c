/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:25 by aalmoman          #+#    #+#             */
/*   Updated: 2026/03/21 11:37:58 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_reachable(t_game *game, char **map, int fd)
{
	int			i;
	int			j;
	t_player	start;

	i = 0;
	start.x = game->player.x;
	start.y = game->player.y;
	check_path(map, position(start.x, start.y));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
			{
				free_map(map);
				error_with_free(game, 0,
					"Error!\nisnt reachable target\n", fd);
			}
			j++;
		}
		i++;
	}
}

void	check_extension(t_game *game, char *str)
{
	int		l;
	char	*t;

	t = str;
	l = ft_strlen(str) - 4;
	t += l;
	if (ft_strncmp(t, ".ber", 4))
		error_with_free(game, 0, "wrong extension\n", -1);
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
	check_extension(game, file);
	check_map(game, fd, file);
	find_player(game);
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
	i = 0;
	while (game->map[i])
	{
		map[i] = ft_strdup(game->map[i]);
		if (!map[i])
		{
			free_map(map);
			error_with_free(game, 0, "Error!\n", fd);
		}
		i++;
	}
	map[i] = NULL;
	is_reachable(game, map, fd);
	free_map(map);
}
