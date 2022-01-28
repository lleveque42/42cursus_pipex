/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:56:56 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/28 18:05:51 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i])
		free(data->path[i++]);
	free(data->path);
	i = 0;
	while (data->cmd1[i])
		free(data->cmd1[i++]);
	free(data->cmd1);
	i = 0;
	while (data->cmd2[i])
		free(data->cmd2[i++]);
	free(data->cmd2);
	free(data->path_cmd1);
	free(data->path_cmd2);
	return (2);
}

int	ft_close_free(t_data *data)
{
	close(data->fd_in);
	close(data->fd_out);
	ft_free(data);
	return (2);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (envp[0] == NULL)
		return (0);
	if (ac != 5 || check_args(av))
		return (wrong_input());
	check_access(&data, av[1], av[4]);
	if (init_data(&data, av[2], av[3]))
		return (ft_free(&data));
	get_data(envp, &data);
	if (parse_cmd(&data) || pipex(&data, envp))
		return (ft_close_free(&data));
	close(data.fd_in);
	close(data.fd_out);
	ft_free(&data);
	return (0);
}
