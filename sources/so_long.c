/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:04:26 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/27 09:32:13 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[1]);
			return (1);
		}
		if (!(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))))
		{
			write(2, "Error\nFile is not a '.ber'", 27);
			return (1);
		}
		data.map = parse_map(fd);
		if (data.map)
			game(data.map);
		free(data.map);
	}
	return (0);
}
