/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:43:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/14 15:17:18 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_start(t_game *game, t_data var, char **map)
{
	var.i = 0;
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (map[var.i][var.j] == 'P')
			{
				game->y = var.i;
				game->x = var.j;
			}
			if (map[var.i][var.j] == 'C')
				game->collectible++;
			if (map[var.i][var.j] == 'E')
				game->exit++;
			var.j++;
		}
		var.i++;
	}
	return ;
}

static void	find_path(t_game *game, int x, int y)
{
	char	c;

	c = game->map_test[y][x];
	if (c == 'C')
	{
		game->collectible -= 1;
		game->map_test[y][x] = 'X';
	}
	else if (c == 'E' && game->collectible == 0)
	{
		game->exit -= 1;
		game->map_test[y][x] = 'X';
	}
	else if (c == '0' || c == 'P')
		game->map_test[y][x] = 'X';
	else
		return ;
	find_path(game, x + 1, y);
	find_path(game, x - 1, y);
	find_path(game, x, y + 1);
	find_path(game, x, y - 1);
}

t_game	init(void)
{
	t_game	game;

	game.i = 0;
	game.j = 0;
	game.x = 0;
	game.y = 0;
	game.collectible = 0;
	game.exit = 0;
	game.start = 0;
	game.move = 0;
	game.error = 0;
	game.map = NULL;
	game.mlx_ptr = NULL;
	game.win_ptr = NULL;
	return (game);
}

char	*check_path_validity(t_data var, char *map)
{
	t_game	game;

	game = init();
	game.map_test = ft_split(map, '\n');
	find_start(&game, var, game.map_test);
	find_path(&game, game.x, game.y);
	if (game.collectible != 0 || game.exit != 0)
	{
		map = map_not_valid(map, "No valid path");
		ft_le_xav(game.map_test);
		return (NULL);
	}
	ft_le_xav(game.map_test);
	return (map);
}
