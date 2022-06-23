/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:10:04 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/23 15:40:42 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(char *src, t_arg *args)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		ft_error("Malloc error", 0, args);
	ft_strlcpy(str, src, ft_strlen(src) + 1);
	return (str);
}
