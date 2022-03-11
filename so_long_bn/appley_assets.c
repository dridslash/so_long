/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appley_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:21:06 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/10 16:59:46 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	apply_assets1(t_data *flow)
{
	flow->wall = "./wall.xpm";
	flow->img_wall = mlx_xpm_file_to_image(flow->mlx, flow->wall,
			&flow->width, &flow->height);
	flow->ground = "./ground.xpm";
	flow->img_ground = mlx_xpm_file_to_image(flow->mlx, flow->ground,
			&flow->width, &flow->height);
	flow->player = "./player.xpm";
	flow->img_player = mlx_xpm_file_to_image(flow->mlx, flow->player,
			&flow->width, &flow->height);
	flow->coin = "./key.xpm";
	flow->img_coin = mlx_xpm_file_to_image(flow->mlx, flow->coin,
			&flow->width, &flow->height);
	flow->door = "./door.xpm";
	flow->img_door = mlx_xpm_file_to_image(flow->mlx, flow->door,
			&flow->width, &flow->height);
			flow->door_opened = "./door_opened.xpm";
	flow->img_door_opened = mlx_xpm_file_to_image(flow->mlx, flow->door_opened,
			&flow->width, &flow->height);
			flow->player_left = "./player_left.xpm";
	flow->img_player_left = mlx_xpm_file_to_image(flow->mlx, flow->player_left,
			&flow->width, &flow->height);
}

void	apply_assets(t_data *flow)
{
	apply_assets1(flow);
			flow->black_screen = "./black_screen.xpm";
	flow->img_black_sc = mlx_xpm_file_to_image(flow->mlx, flow->black_screen,
			&flow->width, &flow->height);
			flow->enemy = "./enemy.xpm";
	flow->img_enemy = mlx_xpm_file_to_image(flow->mlx, flow->enemy,
			&flow->width, &flow->height);
			flow->player_crouch = "./player_crouch.xpm";
	flow->img_player_crouch = mlx_xpm_file_to_image(flow->mlx,
			flow->player_crouch, &flow->width, &flow->height);
			flow->coin_up = "./key_up.xpm";
	flow->img_coin_up = mlx_xpm_file_to_image(flow->mlx, flow->coin_up,
			&flow->width, &flow->height);
}
