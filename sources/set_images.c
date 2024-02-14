/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:37:05 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/14 15:37:26 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!game->img.player_bot || !game->img.player_left
		|| !game->img.player_right || !game->img.player_top)
		return (1);
	return (0);
}

int	set_images(t_game *game)
{
	int	pixels;
	int	error;

	pixels = PXL;
	error = 0;
	game->img.tree = mlx_xpm_file_to_image(game->mlx_ptr,
			TREE, &pixels, &pixels);
	game->img.path = mlx_xpm_file_to_image(game->mlx_ptr,
			PATH, &pixels, &pixels);
	game->img.pokeball = mlx_xpm_file_to_image(game->mlx_ptr,
			POKEBALL, &pixels, &pixels);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT, &pixels, &pixels);
	error = set_img_player(game);
	if (!game->img.tree || !game->img.path || !game->img.pokeball
		|| !game->img.exit || error == 1)
		return (1);
	return (0);
}
