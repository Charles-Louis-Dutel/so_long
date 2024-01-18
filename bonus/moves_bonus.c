/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:04:38 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/18 12:47:01 by cdutel           ###   ########.fr       */
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
		ft_printf("Total moves : %d\n", game->move);
		if (game->map[y][x + 1] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y][x + 1] != 'E')
		{
			if (game->map[y][x + 1] == 'S')
				end_game(game);
			if (game->map[y][x + 1] == 'C')
				game->collectible--;
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.path, (x * 64), (y * 64 + 128));
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.player_right, ((x + 1) * 64), (y * 64 + 128));
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			game->x++;
			game->to_print = 'D';
		}
	}
	else
		game->to_print = 'D';
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
	// 	game->img.player_right, (x * 64), (y * 64 + 128));
	game->update = 1;
}

void	move_left(t_game *game)
{
	int (x) = game->x;
	int (y) = game->y;
	if (game->map[y][x - 1] != '1')
	{
		game->move++;
		ft_printf("Total moves : %d\n", game->move);
		if (game->map[y][x - 1] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y][x - 1] != 'E')
		{
			if (game->map[y][x - 1] == 'S')
				end_game(game);
			if (game->map[y][x - 1] == 'C')
				game->collectible--;
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.path, (x * 64), (y * 64 + 128));
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.player_left, ((x - 1) * 64), (y * 64 + 128));
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			game->x--;
			game->to_print = 'A';
		}
	}
	else
		game->to_print = 'A';
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
	// 	game->img.player_left, (x * 64), (y * 64 + 128));
	game->update = 1;
}

void	move_top(t_game *game)
{
	int (x) = game->x;
	int (y) = game->y;
	if (game->map[y - 1][x] != '1')
	{
		game->move++;
		ft_printf("Total moves : %d\n", game->move);
		if (game->map[y - 1][x] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y - 1][x] != 'E')
		{
			if (game->map[y - 1][x] == 'S')
				end_game(game);
			if (game->map[y - 1][x] == 'C')
				game->collectible--;
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.path, (x * 64), (y * 64 + 128));
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.player_top, (x * 64), ((y - 1) * 64 + 128));
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			game->y--;
			game->to_print = 'W';
		}
	}
	else
		game->to_print = 'W';
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
	// 	game->img.player_top, (x * 64), (y * 64 + 128));
	game->update = 1;
}

void	move_bottom(t_game *game)
{
	int (x) = game->x;
	int (y) = game->y;
	if (game->map[y + 1][x] != '1')
	{
		game->move++;
		ft_printf("Total moves : %d\n", game->move);
		if (game->map[y + 1][x] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y + 1][x] != 'E')
		{
			if (game->map[y + 1][x] == 'S')
				end_game(game);
			if (game->map[y + 1][x] == 'C')
				game->collectible--;
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.path, (x * 64), (y * 64 + 128));
			// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			// 	game->img.player_bot, (x * 64), ((y + 1) * 64 + 128));
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			game->y++;
			game->to_print = 'S';
		}
	}
	else
		game->to_print = 'S';
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
	// 	game->img.player_bot, (x * 64), (y * 64 + 128));
	game->update = 1;
}
