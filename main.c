/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:42 by aalmoman          #+#    #+#             */
/*   Updated: 2026/04/01 00:08:46 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putstr_fd("wrong argument number\n", 1);
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->win = NULL;
	game->map = NULL;
	game->mlx = NULL;
	init_info(argv[1], game);
	if (!initialize_game(game))
	{
		free_mlx(game, 0);
		return (1);
	}
	return (0);
}

void	read_map_lines(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		null_end(line);
		get_map(game->map, i, line, game);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	return ;
}
