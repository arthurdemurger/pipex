/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:02:11 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/23 15:40:42 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_arg *args, char **av, char **envp)
{
	args->fd_1 = open(av[1], O_RDONLY);
	args->fd_2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (args->fd_1 < 0 || args->fd_2 < 0)
		ft_error(PIPE_ERROR, 1, NULL);
	args->cmd_1_args = ft_split(av[2], ' ', args);
	args->cmd_2_args = ft_split(av[3], ' ', args);
	args->cmd_1 = ft_strjoin("/", args->cmd_1_args[0], args);
	args->cmd_2 = ft_strjoin("/", args->cmd_2_args[0], args);
	args->cmd_1_path = NULL;
	args->cmd_2_path = NULL;
	args->env = envp;
}
