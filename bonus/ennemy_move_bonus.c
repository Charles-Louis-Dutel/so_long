/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:24:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/17 19:15:12 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_move(t_game *game, t_enemy *e)
{
	if (e->timer > 100000)
	{
		e->timer = 0;
		if (e->direction == 0)
		{
			if (game->map[e->y][e->x - 1] == '0' || game->map[e->y][e->x - 1] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.path, (e->x * 64), (e->y * 64));
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.smogo_left, ((e->x - 1) * 64), (e->y * 64));
				game->map[e->y][e->x] = '0';
				game->map[e->y][e->x - 1] = 'S';
				e->x--;
			}
			else
				e->direction = 1;
		}
		else
		{
			if (game->map[e->y][e->x + 1] == '0' || game->map[e->y][e->x + 1] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.path, (e->x * 64), (e->y * 64));
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.smogo_left, ((e->x + 1) * 64), (e->y * 64));
				game->map[e->y][e->x] = '0';
				game->map[e->y][e->x + 1] = 'S';
				e->x++;
			}
			else
				e->direction = 0;
		}
	}
	e->timer++;
}

int		ennemy_move(t_game *game)
{
	t_list	*lst;
	t_enemy	*e;

	lst = game->enemy;
	while (lst)
	{
		e = (t_enemy *)lst->content;
		print_move(game, e);
		lst = lst->next;
	}
	return (0);
}

void	init_enemy(t_game *game)
{
	t_enemy	*e;
	int	j;
	int (i) = 0;
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
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
					ft_lstadd_front(&game->enemy, ft_lstnew(e));
			}
			j++;
		}
		i++;
	}
}
