/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:23:28 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/24 15:38:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	**split_free(int index, char **split, t_arg *args)
{
	while (--index)
		free(split[index]);
	free(split);
	ft_error("Malloc error", 0, args);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int		i;
	int		count;
	char	*str;

	str = (char *)s;
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*find_next_word(char *s, char c, int index, t_arg *args)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (index)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			index--;
		while (index && s[i] && s[i] != c)
			i++;
	}
	j = i;
	while (s[j] && s[j] != c)
	{
		count++;
		j++;
	}
	return (ft_substr(&s[i], 0, count, args));
}

char	**ft_split(char const *s, char c, t_arg *args)
{
	char	**str;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (++i < count_words(s, c))
	{
		str[i] = find_next_word((char *)s, c, i + 1, args);
		if (!str[i])
			return (split_free(i, str, args));
	}
	str[i] = 0;
	return (str);
}
