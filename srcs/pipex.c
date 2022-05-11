/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:54:37 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 17:16:22 by ademurge         ###   ########.fr       */
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
}

static void	second_cmd(t_arg *args, int fd, char *cmd)
{
	if (dup2(args->pipe[0], STDIN_FILENO) < 0 || dup2(fd, STDOUT_FILENO) < 0)
		error(DUP2_ERROR);
	close(args->pipe[0]);
	close(fd);
	// EXECVE
}

void	pipex(t_arg *args, char **av, char **envp)
{
	int		pipe_fd[2];
	pid_t	id;

	if ((pipe(pipe_fd)) == -1)
		error(PIPE_ERROR);
	init_struct(args, av, envp, pipe_fd);
	id = fork();
	if (id < 0)
		error(FORK_ERROR);
	else if (id == CHILD)
		first_cmd(args, args->fd_1, args->cmd_1);
	else
		second_cmd(args, args->fd_2, args->cmd_2);
}
