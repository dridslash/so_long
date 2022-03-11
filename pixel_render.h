/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:47:59 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/07 13:24:02 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_RENDER_H
#define PIXEL_RENDER_H

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img_wall;
	void	*img_player;
	void	*img_ground;
	void	*img_coin;
	void	*img_door;
	void	*mlx;
	void	*win;
	char	**map;
	char	*image_path;
	void	*wall;
	void	*player;
	void	*ground;
	void	*door;
	void	*coin;
	int 	width;
	int 	height;
	size_t screen_width;
	size_t screen_height;
	int p_x;
	int p_y;
	int coins_count;
	int pl_moves;
}				t_data;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
void	print_map(t_data *flow);
char	*ft_strdup(const char *src);
char	**ft_read_map();
int		ft_check_map(char **map);
size_t	ft_count_rows();
int		ft_move(int keycode,t_data *flow);
int		render_map(t_data *flow);
void	find_player(t_data *flow);
int		ft_count_elements(char **str);
void	free_map(char **map);

#endif