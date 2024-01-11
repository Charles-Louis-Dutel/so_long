/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:59:21 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/11 01:19:55 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_game *data)
{

    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

void	set_game(t_game *game, char *map_temp)
{
	game->map = ft_split(map_temp, '\n');
	set_images(game);
	print_map(game);
	return ;
}

void	game(char *map)
{
	t_game	game;

	game = init_game();
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return ;
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "so_long");
	if (!game.win_ptr)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		return ;
	}
	mlx_key_hook(game.win_ptr,
				handle_input,
				&game);
	set_game(&game, map);
	mlx_loop(game.mlx_ptr);
	free(map);
}
