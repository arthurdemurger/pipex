/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:46:59 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/12 16:00:47 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ft_is_equal(char *str, char *to_find)
{
	int		i;

	i = -1;
	while (to_find[++i])
		if (str[i] != to_find[i])
			return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	i = -1;
	if (!str || !to_find)
		return (NULL);
	if (!*to_find)
		return (str);
	while (str[++i])
		if (str[i] == *to_find)
			if (ft_is_equal(&str[i], to_find))
				return (&str[i]);
	return (0);
}
