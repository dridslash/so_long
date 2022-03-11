/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:47:59 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/12 10:05:32 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img_wall;
	void	*img_player;
	void	*img_enemy;
	void	*img_player_left;
	void	*img_player_crouch;
	void	*img_ground;
	void	*img_coin;
	void	*img_coin_up;
	void	*img_door;
	void	*img_door_opened;
	void	*mlx;
	void	*win;
	void	*door_opened;
	char	**map;
	char	*image_path;
	void	*wall;
	void	*player;
	void	*ground;
	void	*door;
	void	*player_left;
	void	*coin;
	void	*coin_up;
	void	*enemy;
	void	*player_crouch;
	int		width;
	int		height;
	size_t	screen_width;
	size_t	screen_height;
	int		p_x_win;
	int		p_y_win;
	int		coins_count;
	int		pl_moves;
	int		count_pl;
	int		count_coins;
	int		count_exit;
	int		s_w;
	int		s_h;
	int		p_y_map;
	int		p_x_map;
	int		p_y;
	int		p_x;
	void	*img_black_sc;
	void	*black_screen;
	int		frame;
	int		frame_coin;
	int		frame_enemy;
	int		zero_count;
}				t_data;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
char	*ft_strchr2(const char *s, int c);
void	print_map(t_data *flow);
char	*ft_strdup(const char *src);
char	**ft_read_map(char **argv, t_data *flow);
int		ft_check_map(char **map, char **argv);
size_t	ft_count_rows(char **argv);
int		ft_move(int keycode, t_data *flow);
void	render_map(t_data *flow, char **argv);
void	find_player(t_data *flow);
int		ft_count_elements(char **str, char **argv, t_data *flow);
void	free_map(char **map);
void	apply_assets(t_data *flow);
int		check_is_rectangle(char **map, char **argv);
void	ft_open_door(t_data *flow, char ind);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr(char *str, char	*to_find);
char	*ft_itoa(int n);
int		ft_animation(t_data *flow);
void	ft_win(t_data *flow);
void	ft_up_band(t_data *flow);
void	ft_lose(t_data *flow);
void	ft_animate_enemy(t_data *flow);
void	ft_loop_one(t_data *flow, int x, int y, int place);
void	ft_loop_two(t_data *flow, int x, int y, int place);
// ft_printf

int		ft_printf(const char *pr, ...);

//help_functions

int		ft_linkhex(unsigned long long n);
int		ft_putchar(char c);
int		ft_puthex(unsigned int n);
int		ft_puthexmem(unsigned long long n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putu(unsigned int n);
int		ft_puthexmaj(unsigned int n);

#endif