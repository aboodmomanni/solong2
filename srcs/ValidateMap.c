/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidateMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:00:00 by aalmoman          #+#    #+#             */
/*   Updated: 2026/03/31 23:32:22 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_rows(char **map)
{
	int	i;

	if (!map || !map[0])
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_rectangle(char **map)
{
	int		i;
	size_t	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(char **map)
{
	size_t		i;
	size_t		width;
	size_t		height;

	if (!map || !map[0])
		return (0);
	height = map_rows(map);
	width = ft_strlen(map[0]);
	if (height < 3 || width < 3)
		return (0);
	i = -1;
	while (++i < width)
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
	i = 0;
	while (++i < height - 1)
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
	return (1);
}

int	validate(char **map)
{
	if (!is_rectangle(map))
		return (0);
	if (!check_walls(map))
		return (0);
	if (count_elements(map, 'P') != 1)
		return (0);
	if (count_elements(map, 'E') != 1)
		return (0);
	if (count_elements(map, 'C') < 1)
		return (0);
	if (!valid_chars(map))
		return (0);
	return (1);
}
