/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_new_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:46:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/19 00:49:57 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_player(t_game *game, int xx, int yy)
{
	if (game->to_print == 'W')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_top, xx, yy);
	else if (game->to_print == 'S')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_bot, xx, yy);
	else if (game->to_print == 'A')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_left, xx, yy);
	else if (game->to_print == 'D')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_right, xx, yy);
}

// static void put_enemy(t_game *game, int xx, int yy, int n)
// {
// 	t_list	*lst;
// 	t_enemy	*e;
// 	int		i;

// 	i = 0;
// 	lst = game->enemy;
// 	while (i < n)
// 	{
// 		e = (t_enemy *)lst->content;
// 		lst = lst->next;
// 		i++;
// 	}
// 	if (e->direction == 0)
// 	{
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.smogo_left, xx, yy);
// 		if (game->map[game->i][game->j - 1] == '1' || game->map[game->i][game->j - 1] == 'C')
// 				e->direction = 1;
// 	}
// 	else if (e->direction == 1)
// 	{
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->img.smogo_right, xx, yy);
// 		if (game->map[game->i][game->j + 1] == '1' || game->map[game->i][game->j + 1] == 'C')
// 			e->direction = 0;
// 	}
// 	if (game->n == game->n_enemy)
// 		game->n = 0;
// }

static void	put_sprite_2(t_game *game, char c, int xx, int yy)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.tree, xx, yy);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.path, xx, yy);
	else if (c == 'P')
		put_player(game, xx, yy);
	else if (c == 'C')
	{
		if (game->timer_poke <= 500000)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.pokeball, xx, yy);
		else if (game->timer_poke > 500000 && game->timer_poke < 600000)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.pokeball_up, xx, yy);
		else
			game->timer_poke = 0;
	}
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit, xx, yy);
	else if (c == 'S')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.smogo_left, xx, yy);
}

void	update_hud(t_game *game)
{
	if (game->life == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.empty_heart, 2 * HUD, 0);
	else if (game->life == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.empty_heart, HUD, 0);
	else if (game->life == 0)
		end_game(game);
}

int	get_x_or_y(int i, int j, int game_xy, int size)
{
	int	xy;

	if (game_xy <= i)
		xy = 0;
	else if (game_xy > i && game_xy < size - j)
		xy = i * (game_xy / i);
	else
		xy = size - j;
	return (xy);
}

int	print_map_move(t_game *game)
{
	int (xx) = 0;
	int (yy) = 0;
	if (game->n_enemy > 0)
		ennemy_move(game);
	if (game->update == 1)
	{
		game->i = get_x_or_y(10, 14, game->y, game->height);
		while (game->map[game->i])
		{
			game->j = get_x_or_y(15, 30, game->x, game->len);
			xx = 0;
			while (game->map[game->i][game->j])
			{
				put_sprite_2(game, game->map[game->i][game->j], xx * PXL, yy * PXL + HUD);
				game->j++;
				xx++;
			}
			game->i++;
			yy++;
		}
		game->update = 0;
	}
	update_hud(game);
	return (0);
}
