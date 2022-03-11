/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:15:01 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/10 15:49:36 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_open_door(t_data *flow, char ind)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (ind == 'l')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_player_left, flow->p_x_win, flow->p_y_win);
	if (flow->coins_count == 0)
	{
		while (flow->map[y])
		{
		x = 0;
			while (flow->map[y][x])
			{
				if (flow->map[y][x] == 'E')
				{
					mlx_put_image_to_window(flow->mlx, flow->win,
						flow->img_door_opened, x * 32, (y + 1) * 32);
				}
			x++;
			}
		y++;
		}
	}
}
