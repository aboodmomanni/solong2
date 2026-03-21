/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:35:00 by aalmoman          #+#    #+#             */
/*   Updated: 2026/03/21 11:36:47 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	movement(game, 0, -1);
}

void	move_down(t_game *game)
{
	movement(game, 0, 1);
}

void	move_left(t_game *game)
{
	movement(game, -1, 0);
}

void	move_right(t_game *game)
{
	movement(game, 1, 0);
}

int	end_game(t_game *game)
{
	free_mlx(game, 1);
	return (0);
}
