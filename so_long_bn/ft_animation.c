/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:20:55 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/11 17:44:53 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_player_animate(t_data *flow)
{
	flow->frame++;
	if (flow->frame == 1000)
	{
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_player_crouch, flow->p_x_win, flow->p_y_win);
	}
	if (flow->frame == 5000)
	{
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_player, flow->p_x_win, flow->p_y_win);
		flow->frame = 0;
	}
}

void	animate_frame1(t_data	*flow)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (flow->map[y])
	{
		x = 0;
		while (flow->map[y][x])
		{
			if (flow->map[y][x] == 'C')
			{
				mlx_put_image_to_window(flow->mlx, flow->win,
					flow->img_coin_up, x * 32, (y + 1) * 32);
			}
			x++;
		}
		y++;
	}
}

void	animate_frame2(t_data *flow)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (flow->map[y])
	{
		x = 0;
		while (flow->map[y][x])
		{
			if (flow->map[y][x] == 'C')
			{
				mlx_put_image_to_window(flow->mlx, flow->win,
					flow->img_coin, x * 32, (y + 1) * 32);
			}
			x++;
		}
		y++;
	}
		flow->frame_coin = 0;
}

void	ft_animate_key(t_data *flow)
{
	flow->frame_coin++;
	if (flow->frame_coin == 8000)
	{
		animate_frame1(flow);
	}
	if (flow->frame_coin == 10000)
	{
		animate_frame2(flow);
	}
}

int	ft_animation(t_data *flow)
{
	ft_player_animate(flow);
	ft_animate_key(flow);
	ft_animate_enemy(flow);
	return (1);
}
