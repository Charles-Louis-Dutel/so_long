/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:04:59 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/19 00:16:41 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define PXL 64
# define HUD 128

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../includes/libft.h"
# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	int			i;
	int			j;
	int			collectible;
	int			exit;
	int			start;
	int			line;
	int			len;
	char		*map_line;
	char		*map_temp;
	char		*map;
}	t_data;

typedef struct s_img
{
	void	*tree;
	void	*path;
	void	*exit;
	void	*pokeball;
	void	*pokeball_up;
	void	*player_right;
	void	*player_left;
	void	*player_top;
	void	*player_bot;
	void	*smogo_left;
	void	*smogo_right;
	void	*empty_heart;
	void	*full_heart;
}	t_img;

typedef struct s_enemy
{
	int		direction;
	int		timer;
	int		x;
	int		y;
}	t_enemy;

typedef struct s_game
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		n;
	int		life;
	int		collectible;
	int		start;
	int		exit;
	int		move;
	int		timer_poke;
	int		n_enemy;
	int		to_print;
	int		update;
	int		len;
	int		height;
	char	**map_test;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_list	*enemy;
}	t_game;

/*Parse map*/
char	*parse_map(int fd, t_data data);

/*Check path*/
char	*check_path_validity(t_data var, char *map);
void	find_start(t_game *game, t_data var, char **map);

/*Utils*/
void	ft_le_xav(char **dest);
t_data	init_var(void);
t_game	init_game(void);
char	*map_not_valid(char *map, char *to_print);
void	free_list(t_list **lst);

/*Game*/
void	game(char *map);
int		end_game(t_game *game);

/*Display map*/
void	set_images(t_game *game);
void	print_map(t_game *game);
void	put_sprite(t_game *game, int x, int y);

/*Moves*/
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_top(t_game *game);
void	move_bottom(t_game *game);

/*Ennemy move*/
void	init_enemy(t_game *game);
int		ennemy_move(t_game *game);

int		print_map_move(t_game *game);

#endif
