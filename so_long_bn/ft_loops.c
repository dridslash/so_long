/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:16:08 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/12 16:16:01 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_swap_enemy(t_data *flow, int y, int place)
{
	flow->map[y][place] = '0';
	flow->map[y][place + 1] = 'V';
}

void	ft_swap_enemy_two(t_data *flow, int y, int place)
{
	flow->map[y][place] = '0';
	flow->map[y][place - 1] = 'V';
}

void	ft_loop_two(t_data *flow, int x, int y, int place)
{
	while (flow->map[y])
	{
		x = 0;
		while (flow->map[y][x])
		{
			place = x;
			if (flow->map[y][place] == 'V' && flow->map[y][place - 1] != '1'
				&& flow->map[y][place - 1] != 'C'
				&& flow->map[y][place - 1] != 'E'
				&& flow->map[y][place - 1] != 'V')
			{
				mlx_put_image_to_window(flow->mlx, flow->win,
					flow->img_enemy, (place - 1) * 32, (y + 1) * 32);
				mlx_put_image_to_window(flow->mlx, flow->win,
					flow->img_ground, place * 32, (y + 1) * 32);
				if (flow->map[y][place - 1] == 'P'
						&& flow->map[y][place - 1] != 'C')
					ft_lose(flow);
				else
					ft_swap_enemy_two(flow, y, place);
			}
			x++;
		}
		y++;
	}
}

void	ft_loop_one(t_data *flow, int x, int y, int place)
{
	while (flow->map[y])
	{
			x = 0;
		while (flow->map[y][x])
		{
				place = x;
			if (flow->map[y][place] == 'V' && flow->map[y][place + 1] != '1'
				&& flow->map[y][place + 1] != 'C'
				&& flow->map[y][place + 1] != 'E'
				&& flow->map[y][place + 1] != 'V')
			{
				mlx_put_image_to_window(flow->mlx, flow->win,
					flow->img_ground, place * 32, (y + 1) * 32);
				mlx_put_image_to_window(flow->mlx, flow->win,
					flow->img_enemy, (place + 1) * 32, (y + 1) * 32);
				if (flow->map[y][place + 1] == 'P'
					&& flow->map[y][place + 1] != 'C')
					ft_lose(flow);
				else
					ft_swap_enemy(flow, y, place);
			}
			x++;
		}
		y++;
	}
}
