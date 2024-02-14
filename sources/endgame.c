/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:34:32 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/14 15:04:42 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (game->img.tree)
		mlx_destroy_image(game->mlx_ptr, game->img.tree);
}

int	end_game(t_game *game)
{
	if (game->map)
		ft_le_xav(game->map);
	destroy_images(game);
	if (game->win_ptr && game->mlx_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}
