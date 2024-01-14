/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:16:20 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/14 17:21:35 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_le_xav(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

t_data	init_var(void)
{
	t_data	var;

	var.i = 0;
	var.j = 0;
	var.collectible = 0;
	var.exit = 0;
	var.start = 0;
	var.len = 0;
	var.line = 0;
	return (var);
}

t_game	init_game(void)
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
	return (game);
}

char	*map_not_valid(char *map, char *to_print)
{
	ft_printf("Error\n%s", to_print);
	free(map);
	return (NULL);
}
