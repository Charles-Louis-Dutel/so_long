/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:23:00 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/14 16:40:59 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	set_img_player(t_game *game)
{
	int	pixels;

	pixels = PXL;
	game->img.player_right = mlx_xpm_file_to_image(game->mlx_ptr,
			P_RIGHT, &pixels, &pixels);
	game->img.player_left = mlx_xpm_file_to_image(game->mlx_ptr,
			P_LEFT, &pixels, &pixels);
	game->img.player_top = mlx_xpm_file_to_image(game->mlx_ptr,
			P_TOP, &pixels, &pixels);
	game->img.player_bot = mlx_xpm_file_to_image(game->mlx_ptr,
			P_BOT, &pixels, &pixels);
	game->img.smogo_left = mlx_xpm_file_to_image(game->mlx_ptr,
			S_LEFT, &pixels, &pixels);
	game->img.smogo_right = mlx_xpm_file_to_image(game->mlx_ptr,
			S_RIGTH, &pixels, &pixels);
	game->img.banniere = mlx_xpm_file_to_image(game->mlx_ptr,
			BANNIERE, &pixels, &pixels);
	if (!game->img.player_right || !game->img.player_left
		|| !game->img.player_top || !game->img.player_bot
		|| !game->img.smogo_left || !game->img.smogo_right
		|| !game->img.banniere)
		return (1);
	return (0);
}

static int	set_img_hud_2(t_game *game, int pixels2)
{
	game->img.cinq = mlx_xpm_file_to_image(game->mlx_ptr,
			CINQ, &pixels2, &pixels2);
	game->img.six = mlx_xpm_file_to_image(game->mlx_ptr,
			SIX, &pixels2, &pixels2);
	game->img.sept = mlx_xpm_file_to_image(game->mlx_ptr,
			SEPT, &pixels2, &pixels2);
	game->img.huit = mlx_xpm_file_to_image(game->mlx_ptr,
			HUIT, &pixels2, &pixels2);
	game->img.neuf = mlx_xpm_file_to_image(game->mlx_ptr,
			NEUF, &pixels2, &pixels2);
	game->img.full_heart = mlx_xpm_file_to_image(game->mlx_ptr,
			HEART, &pixels2, &pixels2);
	game->img.empty_heart = mlx_xpm_file_to_image(game->mlx_ptr,
			EMPTY, &pixels2, &pixels2);
	if (!game->img.cinq || !game->img.six || !game->img.sept
		|| !game->img.huit || !game->img.neuf
		|| !game->img.full_heart || !game->img.empty_heart)
		return (1);
	return (0);
}

static int	set_img_hud(t_game *game, int pixels2)
{
	pixels2 = LEN;
	game->img.zero = mlx_xpm_file_to_image(game->mlx_ptr,
			ZERO, &pixels2, &pixels2);
	game->img.un = mlx_xpm_file_to_image(game->mlx_ptr,
			UN, &pixels2, &pixels2);
	game->img.deux = mlx_xpm_file_to_image(game->mlx_ptr,
			DEUX, &pixels2, &pixels2);
	game->img.trois = mlx_xpm_file_to_image(game->mlx_ptr,
			TROIS, &pixels2, &pixels2);
	game->img.quatre = mlx_xpm_file_to_image(game->mlx_ptr,
			QUATRE, &pixels2, &pixels2);
	pixels2 = set_img_hud_2(game, pixels2);
	if (!game->img.zero || !game->img.un || !game->img.deux
		|| !game->img.trois || !game->img.quatre || pixels2 == 1)
		return (1);
	return (0);
}

int	set_images(t_game *game)
{
	int	pixels;
	int	pixels2;

	pixels = PXL;
	pixels2 = HUD;
	game->img.tree = mlx_xpm_file_to_image(game->mlx_ptr,
			TREE, &pixels, &pixels);
	game->img.path = mlx_xpm_file_to_image(game->mlx_ptr,
			PATH, &pixels, &pixels);
	game->img.pokeball = mlx_xpm_file_to_image(game->mlx_ptr,
			POKEBALL, &pixels, &pixels);
	game->img.pokeball_up = mlx_xpm_file_to_image(game->mlx_ptr,
			POKEBALL_UP, &pixels, &pixels);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT, &pixels, &pixels);
	pixels = set_img_player(game);
	pixels2 = set_img_hud(game, pixels2);
	if (!game->img.tree || !game->img.path || !game->img.pokeball
		|| !game->img.pokeball_up || !game->img.exit
		|| pixels == 1 || pixels2 == 1)
		return (1);
	return (0);
}
