/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:34:15 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/13 09:57:32 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	print_map2(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			printf("%c", map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }
int	ft_count_newlines(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n' && temp[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_last_help(char *str, char **temp, int fd)
{
	while (str != NULL)
	{
		(*temp) = ft_strjoin((*temp), str);
		if (ft_count_newlines((*temp)) == 0)
		{
			ft_printf("Error\nSomthing wrong with the map\n");
			exit(1);
		}
		free(str);
		str = get_next_line(fd);
	}
	return (*temp);
}

char	*ft_search(char **ber)
{
	int	i;

	i = 0;
	while (ber[i])
	{
		if (ft_strstr(ber[i], "ber") != NULL)
		{
			return (ber[i]);
		}
		i++;
	}
	return (0);
}

void	ft_help(int fd, char **argv)
{
	if (fd == -1)
	{
		perror("Error :");
		exit(1);
	}
	if (ft_search(argv) == NULL)
	{
		ft_printf("Error\nExtension of file is invalid \n");
		exit(1);
	}
}

char	**ft_read_map(char **argv, t_data *flow)
{
	int		fd;
	char	*str;
	char	*temp;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	ft_help(fd, argv);
	str = get_next_line(fd);
	temp = ft_strdup("");
	map = NULL;
	if (str == NULL)
		return (NULL);
	map = ft_split(ft_last_help(str, &temp, fd), '\n');
	if (ft_count_elements(map, argv, flow) == 1)
	{
		free(temp);
		return (map);
	}
	else if (ft_count_elements(map, argv, flow) == 0)
	{
		free(temp);
		free_map(map);
	}
	return (NULL);
}
