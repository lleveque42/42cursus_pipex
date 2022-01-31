/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:10:40 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/31 13:47:02 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	wrong_input(void)
{
	ft_putstr_fd("pipex: input must look like this : ./pipex infile ", 2);
	ft_putstr_fd("\"cmd1\" \"cmd2\" outfile\n", 2);
	return (2);
}

int	cmd_not_found(char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (1);
}

int	no_file(char *file)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (1);
}

int	cant_init_data(void)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd("can't init data\n", 2);
	return (1);
}

int	cant_find_path(void)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd("can't find path\n", 2);
	return (1);
}
