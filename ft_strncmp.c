/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:30:16 by mnaqqad           #+#    #+#             */
/*   Updated: 2021/11/13 14:34:29 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((ss1[i] && ss2[i]) && (ss1[i] == ss2[i]) && i < n - 1)
	{
		i++;
	}
	return (ss1[i] - ss2[i]);
}
