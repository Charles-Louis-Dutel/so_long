/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:00:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/25 07:50:57 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.banniere, i * HUD, 0);
	i = 11;
	while (i < 15)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.zero, i * HUD, 0);
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

static void	print_move_2(t_game *game, char *count, int len, int i)
{
	if (count[len] == '3')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.trois, i * HUD, 0);
	else if (count[len] == '4')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.quatre, i * HUD, 0);
	else if (count[len] == '5')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.cinq, i * HUD, 0);
	else if (count[len] == '6')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.six, i * HUD, 0);
	else if (count[len] == '7')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.sept, i * HUD, 0);
	else if (count[len] == '8')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.huit, i * HUD, 0);
	else if (count[len] == '9')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.neuf, i * HUD, 0);
}

void	print_move_count(t_game *game)
{
	char	*count;
	int		len;

	int (i) = 14;
	count = ft_itoa(game->move);
	len = (int)ft_strlen(count) - 1;
	if (len > 3)
		return (free(count));
	while (len >= 0)
	{
		if (count[len] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.zero, i * HUD, 0);
		else if (count[len] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.un, i * HUD, 0);
		else if (count[len] == '2')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.deux, i * HUD, 0);
		else if (count[len] >= '3' && count[len] <= '9')
			print_move_2(game, count, len, i);
		i--;
		len--;
	}
	free(count);
}
