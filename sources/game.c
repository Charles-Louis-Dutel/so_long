/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:59:21 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/14 15:35:36 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		return (end_game(game));
	if (keysym == XK_w)
		move_top(game);
	if (keysym == XK_s)
		move_bottom(game);
	if (keysym == XK_a)
		move_left(game);
	if (keysym == XK_d)
		move_right(game);
	return (0);
}

static int	set_game(t_game *game)
{
	int (i) = 0;
	int (j) = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
			}
			if (game->map[i][j] == 'C')
				game->collectible++;
			j++;
		}
		i++;
	}
	print_map(game);
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
	mlx_hook(game.win_ptr, 2, 1L << 0, &handle_input, &game);
	mlx_hook(game.win_ptr, 17, 0L, &end_game, &game);
	mlx_loop(game.mlx_ptr);
}
