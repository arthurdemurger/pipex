/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:06:27 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/23 19:15:30 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
