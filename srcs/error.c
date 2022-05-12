/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:06:27 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/12 15:55:29 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex_error(char *type, int is_perror, t_arg *args)
{
	if (args)
		pipex_free(args);
	if (type && is_perror)
		perror(type);
	else if (type)
		write (1, type, sizeof(type));
	exit(EXIT_FAILURE);
}
