/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:32:57 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/31 15:20:07 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	check_access(t_data *data, char *infile, char *outfile, char **envp)
{
	int	i;

	i = 0;
	data->fd_in = open(infile, O_RDONLY);
	if (data->fd_in <= 0)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(infile);
		exit(2);
	}
	data->fd_out = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_out <= 0)
	{
		close(data->fd_in);
		ft_putstr_fd("pipex: ", 2);
		perror(outfile);
		exit(2);
	}
	while (envp[i])
	{
		if (!ft_strncmp(envp[i++], "PATH=", 5))
			return (0);
	}
	cant_find_path();
	exit(2);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (av[1] == NULL || av[2] == NULL || av[3] == NULL || av[4] == NULL)
		return (1);
	while (av[i])
	{
		j = 0;
		while (av[i][j] && av[i][j] == ' ')
			j++;
		if (!av[i][j] && (i == 1))
			return (no_file(av[i]));
		else if (!av[i][j] && (i == 2 || i == 3))
			return (cmd_not_found(av[i]));
		else if (!av[i][j] && (i == 4))
			return (wrong_input());
		i++;
	}
	return (0);
}
