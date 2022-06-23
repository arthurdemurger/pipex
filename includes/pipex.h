/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:51:52 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/23 16:53:33 by ademurge         ###   ########.fr       */
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
	char	**cmd_1_args;
	char	**cmd_2_args;
	char	*cmd_1_path;
	char	*cmd_2_path;
	char	**env;
	int		fd_1;
	int		fd_2;
	int		pipe[2];
	char	**split_path;
}	t_arg;

/*
** Useful functions
*/

void	ft_error(char *type, int is_perror, t_arg *args);
void	ft_free(t_arg *args);
void	init_struct(t_arg *args, char **av, char **envp);
void	first_cmd(t_arg *args);
void	second_cmd(t_arg *args);
void	parse(t_arg *args);

/*
** Libft functions
*/

char	**ft_split(char const *s, char c, t_arg *args);
char	*ft_strdup(char *src, t_arg *arg);
char	*ft_strjoin(char const *s1, char const *s2, t_arg *args);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_substr(char const *s, unsigned int start, size_t len, t_arg *args);

#endif
