/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:04:59 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/08 18:05:29 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
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
	char			*map_line;
	char			*map_temp;
	char			*map;
}	t_data;

/*Parse map*/
char	*parse_map(int fd, t_data data);

/*Utils*/
void	ft_le_xav(char **dest);
t_data	init_var(void);
char	*map_not_valid(char *map);

#endif
