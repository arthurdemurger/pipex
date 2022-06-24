/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:06:27 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/24 15:38:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_error(char *type, int is_perror, t_arg *args)
{
	if (args)
		ft_free(args);
	if (type && is_perror)
		perror(type);
	else if (type)
		write (STDERR_FILENO, type, ft_strlen(type));
	exit(EXIT_FAILURE);
}
