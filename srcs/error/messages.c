/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:10:40 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 22:06:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	wrong_input(void)
{
	ft_putstr_fd("Input must looks like this : ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
	return (0);
}

int	wrong_infile(char *infile)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(infile, 2);
	ft_putstr_fd(": no such file or directory\n", 2);
	return (1);
}

int	cmd_not_found(char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (1);
}
