/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:43:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/03/05 16:50:52 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (c == 'S')
	{
		if (game->map_test[y][x + 1] == 'X' || game->map_test[y][x + 1] == '0'
		|| game->map_test[y][x + 1] == 'X' || game->map_test[y][x + 1] == '0')
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

static void	find_path_2(t_game *game, int x, int y)
{
	char	c;

	c = game->map_test[y][x];
	if (c == 'E')
	{
		game->exit -= 1;
		game->map_test[y][x] = 'Y';
	}
	else if (c == 'X')
		game->map_test[y][x] = 'Y';
	else
		return ;
	find_path_2(game, x + 1, y);
	find_path_2(game, x - 1, y);
	find_path_2(game, x, y + 1);
	find_path_2(game, x, y - 1);
}

static char	*part_two(t_game game, int x, int y, char *map)
{
	find_path_2(&game, x, y);
	if (game.exit > 0)
	{
		map = map_not_valid(map, "No valid path");
		ft_le_xav(game.map_test);
		return (NULL);
	}
	ft_le_xav(game.map_test);
	return (map);
}

char	*check_path_validity(t_data var, char *map)
{
	t_game	game;
	int		x;
	int		y;

	game = init();
	game.map_test = ft_split(map, '\n');
	if (!game.map_test)
	{
		map = map_not_valid(map, "Malloc error");
		return (NULL);
	}
	find_start(&game, var, game.map_test);
	y = game.y;
	x = game.x;
	find_path(&game, game.x, game.y);
	if (game.collectible > 0)
	{
		map = map_not_valid(map, "No valid path");
		ft_le_xav(game.map_test);
		return (NULL);
	}
	return (part_two(game, x, y, map));
}
