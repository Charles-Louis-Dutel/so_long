/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:16:20 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/19 00:16:59 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game.n = 0;
	game.collectible = 0;
	game.exit = 0;
	game.start = 0;
	game.move = 0;
	game.life = 3;
	game.n_enemy = 0;
	game.enemy = NULL;
	game.to_print = 0;
	game.update = 0;
	game.height = 0;
	game.len = 0;
	game.timer_poke = 0;
	return (game);
}

char	*map_not_valid(char *map, char *to_print)
{
	ft_printf("Error\n%s", to_print);
	free(map);
	return (NULL);
}

void	free_list(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	if (lst && *lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
}
