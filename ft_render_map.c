/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:29:32 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/08 19:10:01 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_help(t_data *flow, int x, int y)
{
	if (flow->map[y][x] == '1')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_wall, x * 32, y * 32);
	if (flow->map[y][x] == '0')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_ground, x * 32, y * 32);
	if (flow->map[y][x] == 'P')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_player, x * 32, y * 32);
	if (flow->map[y][x] == 'C')
	{
		flow->coins_count++;
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_coin, x * 32, y * 32);
	}
	if (flow->map[y][x] == 'E')
		mlx_put_image_to_window(flow->mlx, flow->win,
			flow->img_door, x * 32, y * 32);
}

void	render_map(t_data *flow, char **argv)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	flow->coins_count = 0;
	flow->screen_width = ft_strlen(flow->map[0]);
	flow->screen_height = ft_count_rows(argv);
	flow->win = mlx_new_window(flow->mlx, flow->screen_width * 32,
			flow->screen_height * 32, "so_long");
	apply_assets(flow);
	while (flow->map[y])
	{
		x = 0;
		while (flow->map[y][x])
		{
			map_check_help(flow, x, y);
			x++;
		}
		y++;
	}
}
