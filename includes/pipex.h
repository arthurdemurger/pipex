/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:51:52 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 22:38:05 by ademurge         ###   ########.fr       */
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
	char	**cmd_1;
	char	**cmd_2;
	char	**env;
	int		fd_1;
	int		fd_2;
	int		pipe[2];
	pid_t	pid;
	char	**split_path;
}	t_arg;

/*
** Useful functions
*/

void	error(char *type);
void	init_struct(t_arg *args, char **av, char **envp);
void	pipex(t_arg *args);
void 	parse(t_arg *args);

/*
** Libft functions
*/

char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
