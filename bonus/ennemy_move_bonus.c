/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:24:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/24 23:23:00 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_move_left(t_game *game, int x, int y)
{
	if (game->map[y][x - 1] == '0')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'S';
	}
	else if (game->map[y][x - 1] == 'P')
	{
		game->map[y][x] = 's';
		game->life--;
	}
	else
		game->map[y][x] = 's';
}

void	enemy_move_right(t_game *game, int x, int y)
{
	if (game->map[y][x + 1] == '0')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 's';
	}
	else if (game->map[y][x + 1] == 'P')
	{
		game->map[y][x] = 'S';
		game->life--;
	}
	else
		game->map[y][x] = 'S';
}

void	ennemy_move(t_game *game)
{
	int (x) = 0;
	int (y) = 0;
	if (game->timer_enemy > 100000)
	{
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] == 'S')
						enemy_move_left(game, x, y);
				else if (game->map[y][x] == 's')
				{
						enemy_move_right(game, x, y);
						x++;
				}
				x++;
			}
			y++;
		}
		game->update = 1;
		game->timer_enemy = 0;
	}
	else
		game->timer_enemy++;
}
