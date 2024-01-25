/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:23:00 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/25 07:49:32 by cdutel           ###   ########.fr       */
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

static void	set_img_hud(t_game *game, int pixels2)
{
	int	pixels;

	pixels = LEN;
	game->img.zero = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/zero.xpm", &pixels2, &pixels2);
	game->img.un = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/un.xpm", &pixels2, &pixels2);
	game->img.deux = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/deux.xpm", &pixels2, &pixels2);
	game->img.trois = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/trois.xpm", &pixels2, &pixels2);
	game->img.quatre = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/quatre.xpm", &pixels2, &pixels2);
	game->img.cinq = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/cinq.xpm", &pixels2, &pixels2);
	game->img.six = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/six.xpm", &pixels2, &pixels2);
	game->img.sept = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sept.xpm", &pixels2, &pixels2);
	game->img.huit = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/huit.xpm", &pixels2, &pixels2);
	game->img.neuf = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/neuf.xpm", &pixels2, &pixels2);
	game->img.banniere = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/banniere.xpm", &pixels, &pixels2);
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
	set_img_hud(game, pixels2);
}
