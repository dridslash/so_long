/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:29:32 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/11 11:44:16 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	save_player_pos(t_data *flow)
{
	flow->p_y_win = flow->s_h;
	flow->p_x_win = flow->s_w;
	flow->p_y_map = (flow->p_y_win / 32) - 1;
	flow->p_x_map = flow->p_x_win / 32;
}

void	map_check_help(t_data *flow, int x, int y)
{
	if (flow->map[y][x] == '1')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_wall, flow->s_w, flow->s_h);
	if (flow->map[y][x] == '0')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_ground, flow->s_w, flow->s_h);
	if (flow->map[y][x] == 'P')
	{
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_player, flow->s_w, flow->s_h);
		save_player_pos(flow);
	}
	if (flow->map[y][x] == 'C')
	{
		flow->coins_count++;
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_coin, flow->s_w, flow->s_h);
	}
	if (flow->map[y][x] == 'E')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_door, flow->s_w, flow->s_h);
	if (flow->map[y][x] == 'V')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_enemy, flow->s_w, flow->s_h);
}

void	ft_save_scale(t_data *flow, char **argv)
{
	flow->screen_width = ft_strlen(flow->map[0]);
	flow->screen_height = ft_count_rows(argv);
	flow->win = mlx_new_window(flow->mlx, flow->screen_width * 32,
			((flow->screen_height) * 32) + 32, "so_long_bonus!");
	apply_assets(flow);
}

void	render_map(t_data *flow, char **argv)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	flow->s_w = 0;
	flow->s_h = 32;
	flow->coins_count = 0;
	ft_save_scale(flow, argv);
	while (flow->map[y])
	{
		x = 0;
		flow->s_w = 0;
		while (flow->map[y][x])
		{
			map_check_help(flow, x, y);
			x++;
			flow->s_w += 32;
		}
		y++;
		flow->s_h += 32;
	}
}
