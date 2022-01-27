/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:10:40 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 16:17:54 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	no_env(void)
{
	ft_putstr_fd("Can't find env.\n", 2);
	return (0);
}

int	wrong_input(void)
{
	ft_putstr_fd("Input must looks like this : ./pipex infile ''ls -l'' ''wc -l'' outfile\n", 2);
	return (0);
}
