/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:04:38 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/22 21:54:04 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_right(t_game *game)
{
	int (x) = game->x;
	int (y) = game->y;
	if (game->map[y][x + 1] != '1')
	{
		game->move++;
		print_move_count(game);
		if (game->map[y][x + 1] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y][x + 1] == 'S')
			game->life--;
		else if (game->map[y][x + 1] != 'E' && game->map[y][x + 1] != 'S')
		{
			if (game->map[y][x + 1] == 'C')
				game->collectible--;
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			game->x++;
			game->to_print = 'D';
		}
	}
	else
		game->to_print = 'D';
	game->update = 1;
}

void	move_left(t_game *game)
{
	int (x) = game->x;
	int (y) = game->y;
	if (game->map[y][x - 1] != '1')
	{
		game->move++;
		print_move_count(game);
		if (game->map[y][x - 1] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y][x - 1] == 'S')
			game->life--;
		else if (game->map[y][x - 1] != 'E' && game->map[y][x - 1] != 'S')
		{
			if (game->map[y][x - 1] == 'C')
				game->collectible--;
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			game->x--;
			game->to_print = 'A';
		}
	}
	else
		game->to_print = 'A';
	game->update = 1;
}

void	move_top(t_game *game)
{
	int (x) = game->x;
	int (y) = game->y;
	if (game->map[y - 1][x] != '1')
	{
		game->move++;
		print_move_count(game);
		if (game->map[y - 1][x] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y - 1][x] == 'S')
			game->life--;
		else if (game->map[y - 1][x] != 'E' && game->map[y - 1][x] != 'S')
		{
			if (game->map[y - 1][x] == 'C')
				game->collectible--;
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			game->y--;
			game->to_print = 'W';
		}
	}
	else
		game->to_print = 'W';
	game->update = 1;
}

void	move_bottom(t_game *game)
{
	int (x) = game->x;
	int (y) = game->y;
	if (game->map[y + 1][x] != '1')
	{
		game->move++;
		print_move_count(game);
		if (game->map[y + 1][x] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y + 1][x] == 'S')
				game->life--;
		else if (game->map[y + 1][x] != 'E' && game->map[y + 1][x] != 'S')
		{
			if (game->map[y + 1][x] == 'C')
				game->collectible--;
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			game->y++;
			game->to_print = 'S';
		}
	}
	else
		game->to_print = 'S';
	game->update = 1;
}
