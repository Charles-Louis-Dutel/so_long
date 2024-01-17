/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:59:21 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/14 20:59:12 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game *game)
{
	ft_le_xav(game->map);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.path);
	mlx_destroy_image(game->mlx_ptr, game->img.player_right);
	mlx_destroy_image(game->mlx_ptr, game->img.player_left);
	mlx_destroy_image(game->mlx_ptr, game->img.player_top);
	mlx_destroy_image(game->mlx_ptr, game->img.player_bot);
	mlx_destroy_image(game->mlx_ptr, game->img.pokeball);
	mlx_destroy_image(game->mlx_ptr, game->img.tree);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

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

void	set_game(t_game *game, char *map_temp)
{
	int (i) = 0;
	int (j) = 0;
	game->map = ft_split(map_temp, '\n');
	free(map_temp);
	set_images(game);
	print_map(game);
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
	return ;
}

void	game(char *map)
{
	t_game	game;

	game = init_game();
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return ;
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "so_long");
	if (!game.win_ptr)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		return ;
	}
	set_game(&game, map);
	mlx_hook(game.win_ptr, 2, 1L << 0, &handle_input, &game);
	mlx_hook(game.win_ptr, 17, 0L, &end_game, &game);
	mlx_loop(game.mlx_ptr);
}
