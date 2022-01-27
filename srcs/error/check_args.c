/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:32:57 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 18:59:46 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	check_access(char *infile)
{
	if (access(infile, F_OK))
		return (wrong_infile(infile));
	return (0);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!av[1][0] || !av[2][0] || !av[3][0]|| !av[4][0])
		return (1);
	while (av[i])
	{
		j = 0;
		while (av[i][j] && av[i][j] == ' ')
			j++;
		if (!av[i][j])
			return (1);
		i++;
	}
	return (0);
}
