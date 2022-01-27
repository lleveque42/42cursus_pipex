/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:44:39 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 14:53:44 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	get_cmd(t_path *data, char *cmd1, char *cmd2)
{
	int	i;

	i = 0;
	while (data->path1[i] && data->path2[i])
	{
		data->path1[i] = ft_strjoin(data->path1[i], "/");
		data->path1[i] = ft_strjoin(data->path1[i], cmd1);
		data->path2[i] = ft_strjoin(data->path2[i], "/");
		data->path2[i] = ft_strjoin(data->path2[i], cmd2);
		i++;
	}
	return ;
}

void	get_path(char **envp, t_path *data)
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
				return ;
			break ;
		}
		i++;
	}
	if (str_path)
	{
		data->path1 = ft_split(str_path, ':');
		data->path2 = ft_split(str_path, ':');
	}
	return ;
}
