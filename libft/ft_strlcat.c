/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:06 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/24 15:38:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			size_dest;
	size_t			size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size_dest > size || !src || !dest)
		return (size_src + size);
	j = 0;
	i = size_dest;
	while (src[j] && i + 1 < size)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (size_src + size_dest);
}
