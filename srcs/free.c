/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:41:49 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/24 15:08:36 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_free2(t_arg *args)
{
	int	i;

	if (args->split_path)
	{
		i = 0;
		while (args->split_path[i])
			free(args->split_path[i++]);
		free(args->split_path);
	}
	close(args->fd_1);
	close(args->fd_2);
}

void	ft_free(t_arg *args)
{
	int	i;

	if (args->cmd_1)
		free(args->cmd_1);
	if (args->cmd_2)
		free(args->cmd_2);
	if (args->cmd_1_path)
		free(args->cmd_1_path);
	if (args->cmd_2_path)
		free(args->cmd_2_path);
	if (args->cmd_1_args)
	{
		i = 0;
		while (args->cmd_1_args[i])
			free(args->cmd_1_args[i++]);
		free(args->cmd_1_args);
	}
	if (args->cmd_2_args)
	{
		i = 0;
		while (args->cmd_2_args[i])
			free(args->cmd_2_args[i++]);
		free(args->cmd_2_args);
	}
	ft_free2(args);
}
