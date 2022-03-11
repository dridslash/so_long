/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:04:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/07 16:10:07 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "pixel_render.h"
#include <stdlib.h>

int render_map(t_data *flow)
{
	int y = 0;
	int x = 0;
	flow->coins_count = 0;
	flow->screen_width = ft_strlen(flow->map[0]);
	flow->screen_height = ft_count_rows();
	flow->win = mlx_new_window(flow->mlx,flow->screen_width * 32,flow->screen_height * 32,"my game!");
	while(flow->map[y])
	{
		x = 0;
		while(flow->map[y][x])
		{
			if(flow->map[y][x] == '1')
			{
				flow->wall = "./wall.xpm";
				flow->img_wall = mlx_xpm_file_to_image(flow->mlx,flow->wall,&flow->width,&flow->height);
				mlx_put_image_to_window(flow->mlx,flow->win,flow->img_wall,x * 32,y * 32);
			}
			if(flow->map[y][x] == '0')
			{
				flow->ground = "./ground.xpm";
				flow->img_ground = mlx_xpm_file_to_image(flow->mlx,flow->ground,&flow->width,&flow->height);
				mlx_put_image_to_window(flow->mlx,flow->win,flow->img_ground,x * 32,y * 32);
			}
			if(flow->map[y][x] == 'P')
			{
				flow->player = "./player.xpm";
				flow->img_player = mlx_xpm_file_to_image(flow->mlx,flow->player,&flow->width,&flow->height);
				mlx_put_image_to_window(flow->mlx,flow->win,flow->img_player,x * 32,y * 32);
			}
			if(flow->map[y][x] == 'C')
			{
				flow->coins_count++;
				flow->coin = "./diamond.xpm";
				flow->img_coin = mlx_xpm_file_to_image(flow->mlx,flow->coin,&flow->width,&flow->height);
				mlx_put_image_to_window(flow->mlx,flow->win,flow->img_coin,x * 32,y * 32);
			}
			if(flow->map[y][x] == 'E')
			{
				flow->door = "./door.xpm";
				flow->img_door = mlx_xpm_file_to_image(flow->mlx,flow->door,&flow->width,&flow->height);
				mlx_put_image_to_window(flow->mlx,flow->win,flow->img_door,x * 32,y * 32);
			}
			x++;
		}
		y++;
	}
	return(0);
}

int close_window()
{
	exit(0);
}

int main(void)
{
	t_data *flow = malloc(sizeof(t_data));
	flow->map = ft_read_map();
	if (flow->map == NULL)
	{
		printf("invalid map one of elements is missing \n");
		exit(1);
	}
	else
	{
	flow->mlx = mlx_init();
	render_map(flow);
	find_player(flow);
	flow->pl_moves = 0;
	mlx_hook(flow->win,2,1L<<0,ft_move,flow);
	mlx_hook(flow->win,17,1L>>17,close_window,flow);
	mlx_loop(flow->mlx);
	}
}