/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:51:52 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 17:13:48 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

/*
** Libraries
*/

# include <unistd.h>
# include <sys/wait.h>
# include <assert.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h> // TO DELETE !!!

/*
** Define constants
*/

# define CHILD 0
# define DUP2_ERROR "Dup2 "
# define PIPE_ERROR "Pipe "
# define FORK_ERROR "Fork "
# define OPEN_ERROR "Open "

/*
** Structure
*/

typedef struct s_arg
{
	char	*cmd_1;
	char	*cmd_2;
	char	**env;
	int		fd_1;
	int		fd_2;
	int		pipe[2];
}	t_arg;

/*
** Useful functions
*/

void	error(char *type);
void	init_struct(t_arg *args, char **av, char **envp, int pipe_fd[2]);
void	pipex(t_arg *args, char **av, char **envp);

#endif
