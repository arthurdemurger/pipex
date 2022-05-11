/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:54:37 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 23:21:31 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	first_cmd(t_arg *args)
{
	int		i;
	char	*cmd_path;

	if (dup2(args->fd_1, STDIN_FILENO) < 0 || dup2(args->pipe[1], STDOUT_FILENO) < 0)
		error(DUP2_ERROR);
	close(args->pipe[1]);
	close(args->fd_1);
	i = -1;
	while (args->split_path[++i])
	{
		cmd_path = ft_strjoin(args->split_path[i], args->cmd_1[0]);
		if (!cmd_path)
			error(NULL);
		execve(cmd_path, args->cmd_1, args->env);
		free(cmd_path);
	}
}

static void	second_cmd(t_arg *args)
{
	int		i;
	char	*cmd_path;

	waitpid(args->pid, NULL, 0);
	if (dup2(args->pipe[0], STDIN_FILENO) < 0 || dup2(args->fd_2, STDOUT_FILENO) < 0)
		error(DUP2_ERROR);
	close(args->pipe[0]);
	close(args->fd_2);
	i = -1;
	while (args->split_path[++i])
	{
		cmd_path = ft_strjoin(args->split_path[i], args->cmd_2[0]);
		if (!cmd_path)
			error(NULL);
		execve(cmd_path, args->cmd_2, args->env);
		free(cmd_path);
	}
}

void	pipex(t_arg *args)
{
	parse(args);
	if ((pipe(args->pipe)) == -1)
		error(PIPE_ERROR);
	args->pid = fork();
	if (args->pid < 0)
		error(FORK_ERROR);
	else if (args->pid == CHILD)
		first_cmd(args);
	else
		second_cmd(args);
}
