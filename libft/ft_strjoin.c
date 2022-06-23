/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:23:32 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/23 15:40:42 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2, t_arg *args)
{
	char	*dst;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(sizeof(char) * size);
	if (!dst)
		ft_error("Malloc error", 0, args);
	ft_strlcpy(dst, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(dst, (char *)s2, ft_strlen(s2) + ft_strlen(dst) + 1);
	return (dst);
}
