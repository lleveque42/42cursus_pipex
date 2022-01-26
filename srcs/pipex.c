/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:56:56 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/26 17:44:11 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_env(char **envp, t_path *path)
{
	int		i;
	char	*str_path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			if (!path)
				return (NULL);
			break ;
		}
		i++;
	}
	return (path);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	t_path path;

	i = 0;
	(void)ac;
	(void)av;
	parse_env(envp, path);
}
