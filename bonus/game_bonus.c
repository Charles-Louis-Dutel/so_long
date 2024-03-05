/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:59:21 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/05 15:40:30 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		return (end_game(game));
	else if (keysym == XK_w)
		move_top(game);
	else if (keysym == XK_s)
		move_bottom(game);
	else if (keysym == XK_a)
		move_left(game);
	else if (keysym == XK_d)
		move_right(game);
	return (0);
}

static int	set_game(t_game *game)
{
	while (game->map[game->height])
	{
		game->len = 0;
		while (game->map[game->height][game->len])
		{
			if (game->map[game->height][game->len] == 'P')
			{
				game->x = game->len;
				game->y = game->height;
			}
			if (game->map[game->height][game->len] == 'C')
				game->collectible++;
			if (game->map[game->height][game->len] == 'S')
				game->n_enemy++;
			game->len++;
		}
		game->height++;
	}
	game->to_print = 'D';
	print_hud(game);
	print_start_map(game);
	return (0);
}

void	game(char *map)
{
	t_game	game;

	game = init_game(map);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return ;
	game.error = set_images(&game);
	if (game.error == 1)
		return ((void)end_game(&game));
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "so_long");
	if (!game.win_ptr)
		return ((void)end_game(&game));
	if (set_game(&game) == 1)
		return ((void)end_game(&game));
	mlx_loop_hook(game.mlx_ptr, &print_map_move, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, &handle_input, &game);
	mlx_hook(game.win_ptr, 17, 0L, &end_game, &game);
	mlx_loop(game.mlx_ptr);
}
