/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:54:37 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 19:03:53 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	first_cmd(t_arg *args, int fd, char *cmd)
{
	if (dup2(fd, STDIN_FILENO) < 0 || dup2(args->pipe[1], STDOUT_FILENO) < 0)
		error(DUP2_ERROR);
	close(args->pipe[1]);
	close(fd);
	// EXECVE
	(void) cmd;
}

static void	second_cmd(t_arg *args, int fd, char *cmd)
{
	waitpid(args->pid, NULL, 0);
	if (dup2(args->pipe[0], STDIN_FILENO) < 0 || dup2(fd, STDOUT_FILENO) < 0)
		error(DUP2_ERROR);
	close(args->pipe[0]);
	close(fd);
	// EXECVE
	(void) cmd;
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
		first_cmd(args, args->fd_1, args->cmd_1);
	else
		second_cmd(args, args->fd_2, args->cmd_2);
}
