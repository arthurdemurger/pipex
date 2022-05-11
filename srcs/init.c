/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:02:11 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 22:37:24 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_arg *args, char **av, char **envp)
{
	args->fd_1 = open(av[1], O_RDONLY);
	args->fd_2 = open(av[4], O_RDWR | O_CREAT);
	if (args->fd_1 < 0 || args->fd_2 < 0)
		error(OPEN_ERROR);
	args->cmd_1 = ft_split(av[2], ' ');
	args->cmd_2 = ft_split(av[3], ' ');
	args->env = envp;
}
