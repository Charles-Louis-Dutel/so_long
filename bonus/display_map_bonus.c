/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:00:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/19 00:18:22 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_img_player(t_game *game)
{
	int	pixels;

	pixels = PXL;
	game->img.player_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_right.xpm", &pixels, &pixels);
	game->img.player_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_left.xpm", &pixels, &pixels);
	game->img.player_top = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_top.xpm", &pixels, &pixels);
	game->img.player_bot = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_bot.xpm", &pixels, &pixels);
}

void	set_images(t_game *game)
{
	int	pixels;
	int	pixels2;

	pixels = PXL;
	pixels2 = HUD;
	game->img.tree = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/arbre.xpm", &pixels, &pixels);
	game->img.path = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/chemin.xpm", &pixels, &pixels);
	game->img.pokeball = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/pokeball.xpm", &pixels, &pixels);
	game->img.pokeball_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/pokeball_up.xpm", &pixels, &pixels);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sortie.xpm", &pixels, &pixels);
	game->img.smogo_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/smogo.xpm", &pixels, &pixels);
	game->img.smogo_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/smogo_right.xpm", &pixels, &pixels);
	game->img.full_heart = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/coeur_plein.xpm", &pixels2, &pixels2);
	game->img.empty_heart = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/coeur_vide.xpm", &pixels2, &pixels2);
	set_img_player(game);
}

void	put_sprite(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y / PXL][x / PXL];
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.tree, x, y + HUD);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.path, x, y + HUD);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_right, x, y + HUD);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.pokeball, x, y + HUD);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit, x, y + HUD);
	else if (c == 'S')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.smogo_left, x, y + HUD);
}

static void	print_hud(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.full_heart, i * HUD, 0);
		i++;
	}
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	print_hud(game);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_sprite(game, x * PXL, y * PXL);
			x++;
		}
		y++;
	}
}
