/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:23:31 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 23:15:55 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*search_path(char *line, char *to_find)
{
	char	*str;
	int		i;

	str = ft_strstr(line, to_find);
	i = 0;
	while (str && str[i] && to_find[i])
		i++;
	if (str)
		return(&str[i]);
	return (NULL);
}

void parse(t_arg *args)
{
	int		i;
	char	*line_path;

	i = -1;
	while (args->env[++i])
	{
		line_path = search_path(args->env[i], "PATH=");
		if (line_path)
			break;
	}
	args->split_path = ft_split(line_path, ':');
}