/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:56:56 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 22:28:08 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (envp[0] == NULL)
		return (0);
	if (ac != 5 || check_args(av))
		return (wrong_input());
	if (check_access(av[1]))
		return (0);
	init_data(&data);
	get_data(envp, &data);
	parse_cmd(&data, av[2], av[3]);
	// get_cmd(&data);
}
