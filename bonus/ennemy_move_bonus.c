/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:24:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/24 13:16:07 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_enemy_move_2(t_game *game, t_enemy *e)
{
	if (game->map[e->y][e->x + 1] == '0' || game->map[e->y][e->x + 1] == 'P')
	{
		if (game->map[e->y][e->x + 1] == 'P')
		{
			game->life--;
			e->timer = -500000;
			return ;
		}
		game->map[e->y][e->x] = '0';
		game->map[e->y][e->x + 1] = 'S';
		e->x++;
	}
	else
		e->direction = 0;
}

static void	print_enemy_move(t_game *game, t_enemy *e)
{
	if (e->timer > 100000)
	{
		e->timer = 0;
		game->update = 1;
		if (e->direction == 0)
		{
			if (ft_strchr("0P", game->map[e->y][e->x - 1]))
			{
				if (game->map[e->y][e->x - 1] == 'P')
				{
					game->life--;
					e->timer = -500000;
					return ;
				}
				game->map[e->y][e->x] = '0';
				game->map[e->y][e->x - 1] = 'S';
				e->x--;
			}
			else
				e->direction = 1;
		}
		else
			print_enemy_move_2(game, e);
	}
	e->timer++;
}

void	ennemy_move(t_game *game)
{
	t_list	*lst;
	t_enemy	*e;

	lst = game->enemy;
	while (lst)
	{
		e = (t_enemy *)lst->content;
		print_enemy_move(game, e);
		lst = lst->next;
	}
}

void	init_enemy(t_game *game)
{
	t_enemy	*e;

	int (j) = 0;
	int (i) = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'S')
			{
				e = malloc(sizeof(t_enemy));
				e->direction = 0;
				e->timer = 0;
				e->x = j;
				e->y = i;
				if (game->enemy == NULL)
					game->enemy = ft_lstnew(e);
				else
					ft_lstadd_back(&game->enemy, ft_lstnew(e));
			}
			j++;
		}
		i++;
	}
}
