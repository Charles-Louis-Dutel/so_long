/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:04:59 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/27 09:35:02 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define PXL 64
# define HUD 128
# define LEN 1024

# define TREE "sprites/arbre.xpm"
# define PATH "sprites/chemin.xpm"
# define POKEBALL "sprites/pokeball.xpm"
# define POKEBALL_UP "sprites/pokeball_up.xpm"
# define EXIT "sprites/sortie.xpm"
# define P_RIGHT "sprites/sacha_right.xpm"
# define P_LEFT "sprites/sacha_left.xpm"
# define P_TOP "sprites/sacha_top.xpm"
# define P_BOT "sprites/sacha_bot.xpm"
# define S_LEFT "sprites/smogo.xpm"
# define S_RIGTH "sprites/smogo_right.xpm"
# define HEART "sprites/coeur_plein.xpm"
# define EMPTY "sprites/coeur_vide.xpm"
# define ZERO "sprites/zero.xpm"
# define UN "sprites/un.xpm"
# define DEUX "sprites/deux.xpm"
# define TROIS "sprites/trois.xpm"
# define QUATRE "sprites/quatre.xpm"
# define CINQ "sprites/cinq.xpm"
# define SIX "sprites/six.xpm"
# define SEPT "sprites/sept.xpm"
# define HUIT "sprites/huit.xpm"
# define NEUF "sprites/neuf.xpm"
# define BANNIERE "sprites/banniere.xpm"

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
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
	void	*zero;
	void	*un;
	void	*deux;
	void	*trois;
	void	*quatre;
	void	*cinq;
	void	*six;
	void	*sept;
	void	*huit;
	void	*neuf;
	void	*banniere;
}	t_img;

typedef struct s_game
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		n;
	int		life;
	int		old_life;
	int		collectible;
	int		start;
	int		exit;
	int		move;
	int		timer_enemy;
	int		timer_poke;
	int		n_enemy;
	int		to_print;
	int		update;
	int		len;
	int		height;
	int		error;
	char	**map_test;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_game;

/*Parse map*/
char	*parse_map(int fd);

/*Check path*/
char	*check_path_validity(t_data var, char *map);
void	find_start(t_game *game, t_data var, char **map);

/*Utils*/
void	ft_le_xav(char **dest);
t_data	init_var(void);
t_game	init_game(char *map);
char	*map_not_valid(char *map, char *to_print);

/*Game*/
void	game(char *map);

/*Endgame*/
int		end_game(t_game *game);

/*Display map*/
void	print_map(t_game *game);
void	put_sprite(t_game *game, int x, int y);
void	print_move_count(t_game *game);

/*Set images*/
int		set_images(t_game *game);

/*Moves*/
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_top(t_game *game);
void	move_bottom(t_game *game);

/*Ennemy move*/
void	ennemy_move(t_game *game);

/*Print new map*/
int		print_map_move(t_game *game);

#endif
