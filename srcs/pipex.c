/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:56:56 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 15:24:13 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


int	main(int ac, char **av, char **envp)
{
	t_path	data;

	if (envp[0] == NULL)
		return (no_env());
	if (ac != 5)
		return (wrong_input());
	check_args(av);
	get_path(envp, &data);
	get_cmd(&data, av[2], av[3]);
}
