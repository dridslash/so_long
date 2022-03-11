/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:13:48 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/10 16:04:53 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(char	*str, char	*to_find)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[0])
		{
			k = i;
			while (str[k] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (&str[i]);
				k++;
				j++;
			}
		}
		i++;
	}
	return (0);
}
