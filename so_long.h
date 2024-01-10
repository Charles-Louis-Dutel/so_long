/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:04:59 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/10 11:24:43 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "includes/libft.h"
# include "includes/ft_printf.h"
# include "includes/get_next_line.h"
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

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

typedef struct s_data_2
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		collectible;
	int		start;
	int		exit;
	char	**map_test;
}	t_game;

/*Parse map*/
char	*parse_map(int fd, t_data data);

/*Check path*/
char	*check_path_validity(t_data var, char *map);

/*Utils*/
void	ft_le_xav(char **dest);
t_data	init_var(void);
t_game	init_game(void);
char	*map_not_valid(char *map, char *to_print);

#endif
