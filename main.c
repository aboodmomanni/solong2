/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:02:42 by aalmoman          #+#    #+#             */
/*   Updated: 2026/04/01 23:20:28 by aalmoman         ###   ########.fr       */
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

int	initialize_game(t_game *game)
{
	if (!set_mlx(game))
		return (0);
	if (!set_game(game))
		return (0);
	load_map(game);
	mlx_loop(game->mlx);
	return (1);
}

int	set_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->width * SIZE,
			game->hight * SIZE, "So Long");
	if (!game->win)
		return (0);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 1L << 17, end_game, game);
	return (1);
}
