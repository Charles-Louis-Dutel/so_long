/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:59:21 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/22 21:53:32 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.zero);
	mlx_destroy_image(game->mlx_ptr, game->img.un);
	mlx_destroy_image(game->mlx_ptr, game->img.deux);
	mlx_destroy_image(game->mlx_ptr, game->img.trois);
	mlx_destroy_image(game->mlx_ptr, game->img.quatre);
	mlx_destroy_image(game->mlx_ptr, game->img.cinq);
	mlx_destroy_image(game->mlx_ptr, game->img.six);
	mlx_destroy_image(game->mlx_ptr, game->img.sept);
	mlx_destroy_image(game->mlx_ptr, game->img.huit);
	mlx_destroy_image(game->mlx_ptr, game->img.neuf);
}

int	end_game(t_game *game)
{
	ft_le_xav(game->map);
	free_list(&game->enemy);
	mlx_destroy_image(game->mlx_ptr, game->img.exit);
	mlx_destroy_image(game->mlx_ptr, game->img.path);
	mlx_destroy_image(game->mlx_ptr, game->img.player_right);
	mlx_destroy_image(game->mlx_ptr, game->img.player_left);
	mlx_destroy_image(game->mlx_ptr, game->img.player_top);
	mlx_destroy_image(game->mlx_ptr, game->img.player_bot);
	mlx_destroy_image(game->mlx_ptr, game->img.pokeball);
	mlx_destroy_image(game->mlx_ptr, game->img.pokeball_up);
	mlx_destroy_image(game->mlx_ptr, game->img.tree);
	mlx_destroy_image(game->mlx_ptr, game->img.smogo_left);
	mlx_destroy_image(game->mlx_ptr, game->img.smogo_right);
	mlx_destroy_image(game->mlx_ptr, game->img.full_heart);
	mlx_destroy_image(game->mlx_ptr, game->img.empty_heart);
	destroy_img(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

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
	//print_move_count(game);
	return (0);
}

void	set_game(t_game *game, char *map_temp)
{
	game->map = ft_split(map_temp, '\n');
	free(map_temp);
	set_images(game);
	print_map(game);
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
	if (game.n_enemy > 0)
		init_enemy(&game);
	mlx_loop_hook(game.mlx_ptr, &print_map_move, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, &handle_input, &game);
	mlx_hook(game.win_ptr, 17, 0L, &end_game, &game);
	mlx_loop(game.mlx_ptr);
}
