/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:58:42 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/12 16:25:59 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_arg	args;

	if (ac == 5)
	{
		init_struct(&args, av, envp);
		parse(&args);
		if ((pipe(args.pipe)) == -1)
			pipex_error(PIPE_ERROR, 1, NULL);
		first_cmd(&args);
		second_cmd(&args);
		pipex_free(&args);
	}
	else
		pipex_error("Invalid number of arguments\n", 0, NULL);
}
