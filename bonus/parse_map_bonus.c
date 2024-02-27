/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:18:23 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/27 09:35:50 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*check_line_and_characters(t_data var, char *map)
{
	while (map[var.len] && map[var.len] != '\n')
		var.len++;
	while (map[var.i])
	{
		if (map[var.i] == '\n' || map[var.i + 1] == '\0')
		{
			if (var.j != var.len)
				return (map_not_valid(map, "Map is not rectangular"));
			var.line++;
			var.j = -1;
		}
		else if (map[var.i] == 'C')
			var.collectible++;
		else if (map[var.i] == 'P')
			var.start++;
		else if (map[var.i] == 'E')
			var.exit++;
		var.j++;
		var.i++;
	}
	if (var.start != 1 || var.exit != 1 || var.collectible < 1)
		return (map_not_valid(map,
				"Wrong number of collectibles, player or exit"));
	return (map);
}

static char	*is_map_closed(t_data var, char *map)
{
	while (map[var.len] && map[var.len] != '\n')
		var.len++;
	var.i = 0;
	while (map[var.i])
	{
		if (map[var.i] == '\n')
			var.line++;
		var.i++;
	}
	var.i = 0;
	var.j = 1;
	while (map[var.i])
	{
		if (map[var.i] == '\n')
			var.j++;
		else if (var.j == 1 && map[var.i] != '1')
			return (map_not_valid(map, "Map is not closed"));
		else if (var.j > 1 && var.j < var.line && (map[var.i - 1] == '\n'
				|| map[var.i + 1] == '\n') && map[var.i] != '1')
			return (map_not_valid(map, "Map is not closed"));
		else if (var.j == var.line && map[var.i] != '1')
			return (map_not_valid(map, "Map is not closed"));
		var.i++;
	}
	return (map);
}

static char	*check_map_validity(char *map)
{
	t_data	var;

	var = init_var();
	map = check_line_and_characters(var, map);
	if (!map)
		return (NULL);
	while (map[var.i])
	{
		if (!ft_strchr("01PCES\n", map[var.i]))
			return (map_not_valid(map, "Wrong character"));
		var.i++;
	}
	map = is_map_closed(var, map);
	if (!map)
		return (NULL);
	var = init_var();
	map = check_path_validity(var, map);
	if (!map)
		return (NULL);
	return (map);
}

char	*parse_map(int fd)
{
	t_data	data;

	data.map_temp = (char *)malloc(1 * sizeof(char));
	if (!data.map_temp)
		return (NULL);
	data.map_temp[0] = '\0';
	while (1)
	{
		data.map_line = get_next_line(fd);
		if (data.map_line == NULL)
			break ;
		if (data.map_temp[0] == '\0')
		{
			free(data.map_temp);
			data.map_temp = ft_strdup(data.map_line);
		}
		else
			data.map_temp = ft_strjoin(data.map_temp, data.map_line);
		free(data.map_line);
		if (!data.map_temp)
			return (free(data.map_temp), NULL);
	}
	data.map = check_map_validity(data.map_temp);
	return (data.map);
}
