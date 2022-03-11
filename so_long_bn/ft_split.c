/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:21:14 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/12 15:59:27 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_sepcount(char const *s, char const c)
{
	int	i;
	int	spl;

	i = 0;
	spl = 0;
	if (s[0] != c && s[0] != '\0')
	spl++;
	if (spl > 0)
	i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c) && (s[i + 1] != '\0'))
		{
			spl++;
		}
		i++;
	}
	return (spl);
}

static int	ft_wordcount(char const *s, char const c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_fill(char **cpy, int spl, char c, const char *s)
{
	int	k;
	int	j;
	int	i;

	i = 0;
	k = 0;
	j = 0;
	while (i <= (spl - 1))
	{
		while (s[j] == c)
			j++;
		k = ft_wordcount(&s[j], c);
		cpy[i] = (char *)malloc(sizeof(char) * k + 1);
		if (!cpy[i])
			return (0);
		k = 0;
		while (s[j] != c && s[j] != '\0')
		{
			cpy[i][k++] = s[j++];
		}
		cpy[i][k] = '\0';
		i++;
	}
	cpy[i] = NULL;
	return (1);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		spl;
	char	**cpy;
	int		check;

	i = 0;
	if (s == NULL)
		return (NULL);
	spl = ft_sepcount(s, c);
	cpy = (char **) malloc(sizeof(char *) * (spl + 1));
	if (cpy == NULL)
		exit(1);
	check = ft_fill(cpy, spl, c, s);
	if (check == 0)
		free(cpy);
	return (cpy);
}
// int main(void)
// {
// 	char s='\0';
// 	char *s1="      kljl    klklk  l       ";
// 	char **d=ft_split(s1,s);
// 	while(*d)
// 	{
// 		printf("%s\n",*d);
// 		d++;
// 	}
// }
