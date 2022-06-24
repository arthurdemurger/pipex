/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:02:11 by ademurge          #+#    #+#             */
/*   Updated: 2022/06/24 15:38:41 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*cut_path(char *s, char c, t_arg *args)
{
	int		i;

	i = ft_strlen(s);
	while (--i >= 0)
		if (s[i] == c && i)
			return (ft_strdup(&s[i + 1], args));
	return (s);
}

void	init_struct(t_arg *args, char **av, char **envp)
{
	char	*tmp1;
	char	*tmp2;

	args->fd_1 = open(av[1], O_RDONLY);
	args->fd_2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC);
	if (args->fd_1 < 0 || args->fd_2 < 0)
		ft_error(OPEN_ERROR, 1, NULL);
	args->cmd_1_args = ft_split(av[2], ' ', args);
	args->cmd_2_args = ft_split(av[3], ' ', args);
	tmp1 = cut_path(args->cmd_1_args[0], '/', args);
	tmp2 = cut_path(args->cmd_2_args[0], '/', args);
	args->cmd_1 = ft_strjoin("/", tmp1, args);
	args->cmd_2 = ft_strjoin("/", tmp2, args);
	args->cmd_1_path = NULL;
	args->cmd_2_path = NULL;
	args->env = envp;
	if (ft_strcmp(tmp1, args->cmd_1_args[0]))
		free(tmp1);
	if (ft_strcmp(tmp2, args->cmd_2_args[0]))
		free(tmp2);
	if ((pipe(args->pipe)) == -1)
		ft_error(PIPE_ERROR, 1, NULL);
}
