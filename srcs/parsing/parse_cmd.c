/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:50:48 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 22:28:00 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int		check_cmd(t_data *data, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (data->path[i])
	{
		cmd = ft_strjoin(data->path[i], "/");
		cmd = ft_strjoin(cmd, cmd);
		if (!access(cmd, F_OK))

			check = 1;
		i++;
	}
	if (!check)
		return (cmd_not_found(data->cmd1[0]));
}

void	get_cmd(t_data *data, char *cmd1, char *cmd2)
{
	int	i;

	i = 0;
	while (data->path[i])
	{
		data->path[i] = ft_strjoin(data->path[i], "/");
		data->path[i] = ft_strjoin(data->path[i], cmd1);
		data->path[i] = ft_strjoin(data->path[i], "/");
		data->path[i] = ft_strjoin(data->path[i], cmd2);
		i++;
	}
	return ;
}

int	parse_cmd(t_data *data, char *cmd1, char *cmd2)
{
	data->cmd1 = ft_split(cmd1, ' ');
	data->cmd2 = ft_split(cmd2, ' ');
	if (check_cmd(data))
		return (1);
	// while (data->cmd1[i][0])
	for (int i = 0; data->cmd1[i]; i++)
		printf("%s\n", data->cmd1[i]);
	for (int i = 0; data->cmd2[i]; i++)
		printf("%s\n", data->cmd2[i]);
	return (0);
}
