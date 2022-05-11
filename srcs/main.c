/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:58:42 by ademurge          #+#    #+#             */
/*   Updated: 2022/05/11 18:53:17 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_arg	args;

	if (ac == 5)
	{
		init_struct(&args, av, envp);
		pipex(&args);
	}
	else
		write (1, "Invalid number of arguments\n", 29);
}
