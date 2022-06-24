/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:22:47 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/24 15:38:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len, t_arg *args)
{
	char	*src;
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("", args));
	size = ft_strlen(&s[start]);
	if (size > len)
		size = len;
	src = (char *)s;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		ft_error("Malloc error", 0, args);
	ft_strlcpy(str, &src[start], size + 1);
	return (str);
}
