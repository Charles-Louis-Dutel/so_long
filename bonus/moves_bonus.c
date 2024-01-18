/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:04:38 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/17 23:14:28 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// void	put_sprite_2(t_game *game, int x, int xx, int y, int yy)
// {
// 	char	c;

// 	c = game->map[y][x];
// 	if (c == '1')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.tree, xx, yy);
// 	else if (c == '0')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.path, xx, yy);
// 	else if (c == 'P')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.player_right, xx, yy);
// 	else if (c == 'C')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.pokeball, xx, yy);
// 	else if (c == 'E')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.exit, xx, yy);
// 	else if (c == 'S')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.smogo_left, xx, yy);
// }


// void	print_map_move(t_game *game, int ix, int iy)
// {
// 	int	x;
// 	int	xx;
// 	int	(y) = 0;
// 	int	(yy) = 0;
// 	mlx_clear_window(game->mlx_ptr, game->win_ptr);
// 	if (iy > 10)
// 		y = iy - 10;
// 	while (game->map[y])
// 	{
// 		if (ix > 20)
// 			x = ix - 20;
// 		else
// 			x = 0;
// 		xx = 0;
// 		while (game->map[y][x])
// 		{
// 			put_sprite_2(game, x, xx * 64, y, yy * 64);
// 			x++;
// 			xx++;
// 		}
// 		y++;
// 		yy++;
// 	}
// }

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
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64 + 128));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player_right, ((x + 1) * 64), (y * 64 + 128));
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			//print_map_move(game, x, y);
			game->x++;
		}
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_right, (x * 64), (y * 64 + 128));
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
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64 + 128));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player_left, ((x - 1) * 64), (y * 64 + 128));
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			//print_map_move(game, x, y);
			game->x--;
		}
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_left, (x * 64), (y * 64 + 128));
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
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64 + 128));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player_top, (x * 64), ((y - 1) * 64 + 128));
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			//print_map_move(game, x, y);
			game->y--;
		}
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_top, (x * 64), (y * 64 + 128));
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
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64 + 128));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player_bot, (x * 64), ((y + 1) * 64 + 128));
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			//print_map_move(game, x, y);
			game->y++;
		}
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_bot, (x * 64), (y * 64 + 128));
}
