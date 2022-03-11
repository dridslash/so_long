/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:15:21 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/12 14:21:36 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_right(t_data *flow)
{
	if (flow->map[flow->p_y_map][flow->p_x_map + 1] != '1'
	&& flow->map[flow->p_y_map][flow->p_x_map + 1] != 'E')
	{
		if (flow->map[flow->p_y_map][flow->p_x_map + 1] == 'V')
			ft_lose(flow);
		flow->pl_moves++;
		if (flow->map[flow->p_y_map][flow->p_x_map + 1] == 'C')
		{
			flow->map[flow->p_y_map][flow->p_x_map + 1] = '0';
			flow->coins_count--;
		}
		mlx_put_image_to_window(flow->mlx, flow->win, flow->img_ground,
			flow->p_x_win, flow->p_y_win);
		mlx_put_image_to_window(flow->mlx, flow->win, flow->img_player,
			flow->p_x_win + 32, flow->p_y_win);
		flow->map[flow->p_y_map][flow->p_x_map + 1] = 'P';
		flow->map[flow->p_y_map][flow->p_x_map] = '0';
		flow->p_x_map++;
		flow->p_x_win += 32;
		ft_up_band(flow);
		ft_open_door(flow, 'r');
	}
	else if (flow->map[flow->p_y_map][flow->p_x_map + 1] == 'E'
			&& flow->coins_count == 0)
		ft_win(flow);
}

void	ft_move_left(t_data *flow)
{
	if (flow->map[flow->p_y_map][flow->p_x_map - 1] != '1'
		&& flow->map[flow->p_y_map][flow->p_x_map - 1] != 'E')
	{
		if (flow->map[flow->p_y_map][flow->p_x_map - 1] == 'V')
			ft_lose(flow);
		flow->pl_moves++;
		if (flow->map[flow->p_y_map][flow->p_x_map - 1] == 'C')
		{
			flow->map[flow->p_y_map][flow->p_x_map - 1] = '0';
			flow->coins_count--;
		}
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_ground, flow->p_x_win, flow->p_y_win);
		mlx_put_image_to_window(flow->mlx, flow->win, flow->img_player,
			flow->p_x_win - 32, flow->p_y_win);
		flow->map[flow->p_y_map][flow->p_x_map - 1] = 'P';
		flow->map[flow->p_y_map][flow->p_x_map] = '0';
		flow->p_x_map--;
		flow->p_x_win -= 32;
		ft_up_band(flow);
		ft_open_door(flow, 'r');
	}
	else if (flow->map[flow->p_y_map][flow->p_x_map - 1] == 'E'
			&& flow->coins_count == 0)
		ft_win(flow);
}

void	ft_move_up(t_data *flow)
{
	if (flow->map[flow->p_y_map - 1][flow->p_x_map] != '1'
		&& flow->map[flow->p_y_map - 1][flow->p_x_map] != 'E')
	{
		if (flow->map[flow->p_y_map - 1][flow->p_x_map] == 'V')
			ft_lose(flow);
		flow->pl_moves++;
		if (flow->map[flow->p_y_map - 1][flow->p_x_map] == 'C')
		{
			flow->map[flow->p_y_map - 1][flow->p_x_map] = '0';
			flow->coins_count--;
		}
		mlx_put_image_to_window(flow->mlx, flow->win, flow->img_ground,
			flow->p_x_win, flow->p_y_win);
		mlx_put_image_to_window(flow->mlx, flow->win, flow->img_player,
			flow->p_x_win, flow->p_y_win - 32);
		flow->map[flow->p_y_map - 1][flow->p_x_map] = 'P';
		flow->map[flow->p_y_map][flow->p_x_map] = '0';
		flow->p_y_map--;
		flow->p_y_win -= 32;
		ft_up_band(flow);
		ft_open_door(flow, 'r');
	}
	else if (flow->map[flow->p_y_map - 1][flow->p_x_map] == 'E'
			&& flow->coins_count == 0)
		ft_win(flow);
}

void	ft_move_down(t_data *flow)
{
	if (flow->map[flow->p_y_map + 1][flow->p_x_map] != '1'
		&& flow->map[flow->p_y_map + 1][flow->p_x_map] != 'E')
	{
		if (flow->map[flow->p_y_map + 1][flow->p_x_map] == 'V')
			ft_lose(flow);
		flow->pl_moves++;
		if (flow->map[flow->p_y_map + 1][flow->p_x_map] == 'C')
		{
			flow->map[flow->p_y_map + 1][flow->p_x_map] = '0';
			flow->coins_count--;
		}
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_ground, flow->p_x_win, flow->p_y_win);
		mlx_put_image_to_window(flow->mlx, flow->win, flow->img_player,
			flow->p_x_win, flow->p_y_win + 32);
		flow->map[flow->p_y_map + 1][flow->p_x_map] = 'P';
		flow->map[flow->p_y_map][flow->p_x_map] = '0';
		flow->p_y_map++;
		flow->p_y_win += 32;
		ft_up_band(flow);
		ft_open_door(flow, 'r');
	}
	else if (flow->map[flow->p_y_map + 1][flow->p_x_map] == 'E'
			&& flow->coins_count == 0)
		ft_win(flow);
}

int	ft_move(int keycode, t_data *flow)
{
	if (keycode == 2)
	{
		ft_move_right(flow);
	}
	if (keycode == 0)
	{
		ft_move_left(flow);
	}
	if (keycode == 13)
	{
		ft_move_up(flow);
	}
	if (keycode == 1)
	{
		ft_move_down(flow);
	}
	if (keycode == 53 || keycode == 12)
	{
		ft_printf("\033[1;33m you Quit the Game :c !!");
		mlx_destroy_window(flow->mlx, flow->win);
		exit(1);
	}
	return (1);
}
