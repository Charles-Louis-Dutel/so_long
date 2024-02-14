/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:54:24 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/14 16:36:39 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_images_2(t_game *game)
{
	if (game->img.zero)
		mlx_destroy_image(game->mlx_ptr, game->img.zero);
	if (game->img.un)
		mlx_destroy_image(game->mlx_ptr, game->img.un);
	if (game->img.deux)
		mlx_destroy_image(game->mlx_ptr, game->img.deux);
	if (game->img.trois)
		mlx_destroy_image(game->mlx_ptr, game->img.trois);
	if (game->img.quatre)
		mlx_destroy_image(game->mlx_ptr, game->img.quatre);
	if (game->img.cinq)
		mlx_destroy_image(game->mlx_ptr, game->img.cinq);
	if (game->img.six)
		mlx_destroy_image(game->mlx_ptr, game->img.six);
	if (game->img.sept)
		mlx_destroy_image(game->mlx_ptr, game->img.sept);
	if (game->img.huit)
		mlx_destroy_image(game->mlx_ptr, game->img.huit);
	if (game->img.neuf)
		mlx_destroy_image(game->mlx_ptr, game->img.neuf);
	if (game->img.full_heart)
		mlx_destroy_image(game->mlx_ptr, game->img.full_heart);
	if (game->img.empty_heart)
		mlx_destroy_image(game->mlx_ptr, game->img.empty_heart);
}

void	destroy_images(t_game *game)
{
	if (game->img.exit)
		mlx_destroy_image(game->mlx_ptr, game->img.exit);
	if (game->img.path)
		mlx_destroy_image(game->mlx_ptr, game->img.path);
	if (game->img.player_right)
		mlx_destroy_image(game->mlx_ptr, game->img.player_right);
	if (game->img.player_left)
		mlx_destroy_image(game->mlx_ptr, game->img.player_left);
	if (game->img.player_top)
		mlx_destroy_image(game->mlx_ptr, game->img.player_top);
	if (game->img.player_bot)
		mlx_destroy_image(game->mlx_ptr, game->img.player_bot);
	if (game->img.pokeball)
		mlx_destroy_image(game->mlx_ptr, game->img.pokeball);
	if (game->img.pokeball_up)
		mlx_destroy_image(game->mlx_ptr, game->img.pokeball_up);
	if (game->img.tree)
		mlx_destroy_image(game->mlx_ptr, game->img.tree);
	if (game->img.smogo_left)
		mlx_destroy_image(game->mlx_ptr, game->img.smogo_left);
	if (game->img.smogo_right)
		mlx_destroy_image(game->mlx_ptr, game->img.smogo_right);
	if (game->img.banniere)
		mlx_destroy_image(game->mlx_ptr, game->img.banniere);
}

int	end_game(t_game *game)
{
	if (game->map)
		ft_le_xav(game->map);
	destroy_images(game);
	destroy_images_2(game);
	if (game->win_ptr && game->mlx_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}
