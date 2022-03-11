/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_element_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:33:19 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/12 17:46:25 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_handle_zeros(t_data *flow, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
			{
				flow->zero_count++;
			}
				j++;
		}
	i++;
	}
}

int	ft_global_helper(t_data *flow, char **str)
{
	ft_handle_zeros(flow, str);
	if ((flow->count_pl != 1 || flow->count_coins == 0
			|| flow->count_exit == 0) || flow->zero_count == 0)
	{
		return (0);
	}
	return (1);
}

void	ft_check_other_elemenst(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E' || str[i][j] == 'P' || str[i][j] == 'C'
				|| str[i][j] == '1' || str[i][j] == '0' || str[i][j] == 'V')
			{
			}
			else
			{
				ft_printf("Error\nelement not recognized \n");
				exit(1);
			}
				j++;
		}
			i++;
	}
}

static int	ft_element_helper(char **str, t_data *flow, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			flow->count_pl++;
			if (str[i][j] == 'C')
			flow->count_coins++;
			if (str[i][j] == 'E')
			flow->count_exit++;
			j++;
		}
		i++;
	}
	ft_check_other_elemenst(str);
	if ((ft_check_map(str, argv) == 0 || check_is_rectangle(str, argv) == 0))
		return (0);
	return (ft_global_helper(flow, str));
	return (1);
}

int	ft_count_elements(char **str, char **argv, t_data *flow)
{
	flow->count_pl = 0;
	flow->count_coins = 0;
	flow->count_exit = 0;
	flow->zero_count = 0;
	return (ft_element_helper(str, flow, argv));
}
