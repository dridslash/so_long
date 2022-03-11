/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchecker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:41:34 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/13 12:09:04 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

size_t	ft_count_rows(char **argv)
{
	int		count;
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		perror("Error\n");
	str = get_next_line(fd);
	count = 0;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		count ++;
	}
	close(fd);
	return (count);
}

int	check_is_rectangle(char **map, char **argv)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[0]) == ft_strlen(map[i])
			&& (ft_strlen(map[0])) != ft_count_rows(argv))
		{
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map(char **map, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j] && map[ft_count_rows(argv) - 1][j])
	{
		if (map[0][j] == '1' && map[ft_count_rows(argv) - 1][j] == '1')
			j++;
		else
			return (0);
	}
	while (map[i])
	{
		if (map[i][0] == '1' && map[i][ft_strlen(map[i]) - 1] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}
