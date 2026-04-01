/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapMaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:21:55 by aalmoman          #+#    #+#             */
/*   Updated: 2026/04/01 23:28:10 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	position(int col, int row)
{
	t_pos	pos;

	pos.col = col;
	pos.row = row;
	return (pos);
}

void	check_path(char **map, t_pos tile)
{
	if (tile.row < 0 || tile.col < 0 || !map[tile.row]
		|| !map[tile.row][tile.col])
		return ;
	if (map[tile.row][tile.col] == '1')
		return ;
	map[tile.row][tile.col] = '1';
	check_path(map, position(tile.col - 1, tile.row));
	check_path(map, position(tile.col + 1, tile.row));
	check_path(map, position(tile.col, tile.row - 1));
	check_path(map, position(tile.col, tile.row + 1));
}

void	null_end(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	get_map(char **map, int pos, char *line, t_game *game)
{
	int	i;

	i = 0;
	map[pos] = malloc(ft_strlen(line) + 1);
	if (!map[pos])
		error_with_free(game, 0, "Error!\n", -1);
	while (line[i])
	{
		map[pos][i] = line[i];
		i++;
	}
	map[pos][i] = '\0';
}
