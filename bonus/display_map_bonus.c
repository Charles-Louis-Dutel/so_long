/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:00:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/05 17:19:51 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_hud(t_game *game)
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

void	print_start_map(t_game *game)
{
	int (xx) = 0;
	int (yy) = 0;
	game->i = get_x_or_y(10, 14, game->y, game->height);
	while (game->map[game->i])
	{
		game->j = get_x_or_y(15, 30, game->x, game->len);
		xx = 0;
		while (game->map[game->i][game->j])
		{
			put_sprite_2(game, game->map[game->i][game->j],
				xx * PXL, yy * PXL + HUD);
			game->j++;
			xx++;
		}
		game->i++;
		yy++;
	}
}
