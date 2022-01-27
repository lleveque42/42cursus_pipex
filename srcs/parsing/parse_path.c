/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:44:39 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 22:28:04 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	get_data(char **envp, t_data *data)
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
		data->path = ft_split(str_path, ':');
	return ;
}
