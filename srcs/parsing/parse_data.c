/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:44:39 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/28 14:32:47 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	get_data(char **envp, t_data *data)
{
	int		i;
	char	*str_path;

	i = 0;
	str_path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			str_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			if (!str_path)
				return (cant_init_data());
			break ;
		}
		i++;
	}
	if (str_path)
		data->path = ft_split(str_path, ':');
	free(str_path);
	return (0);
}

int	init_data(t_data *data, char *cmd1, char *cmd2)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->path = NULL;
	data->path_cmd1 = NULL;
	data->path_cmd2 = NULL;
	data->cmd1 = ft_split(cmd1, ' ');
	data->cmd2 = ft_split(cmd2, ' ');
	if (!data->cmd1 || !data->cmd2)
		return (cant_init_data());
	return (0);
}
