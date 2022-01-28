/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:50:48 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/28 16:11:18 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*get_path(char *path, char *cmd)
{
	char	*cmd_path;

	cmd_path = ft_strjoin(path, "/");
	if (!cmd_path)
		return (NULL);
	cmd_path = ft_strjoin(cmd_path, cmd);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}

int	check_cmd(t_data *data, char *cmd, int cmd_i)
{
	int		i;
	char	*path;
	char	*cmd_path;

	i = 0;
	while (data->path[i])
	{
		path = ft_strdup(data->path[i]);
		if (!path)
			return (cant_init_data());
		cmd_path = get_path(path, cmd);
		if (!cmd_path)
			return (cant_init_data());
		if (!access(cmd_path, F_OK))
		{
			if (cmd_i == 1)
				data->path_cmd1 = cmd_path;
			else
				data->path_cmd2 = cmd_path;
			return (0);
		}
		free(cmd_path);
		i++;
	}
	return (cmd_not_found(cmd));
}

int	parse_cmd(t_data *data)
{
	if (!access(data->cmd1[0], F_OK))
		data->path_cmd1 = ft_strdup(data->cmd1[0]);
	else
	{
		if (check_cmd(data, data->cmd1[0], 1))
			return (1);
	}
	if (!access(data->cmd2[0], F_OK))
		data->path_cmd2 = ft_strdup(data->cmd2[0]);
	else
	{
		if (check_cmd(data, data->cmd2[0], 2))
			return (1);
	}
	return (0);
}
