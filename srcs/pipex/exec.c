/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:17:07 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/28 18:21:29 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	child_two(t_data *data, char **envp)
{
	if (dup2(data->fd_out, STDOUT_FILENO) == -1)
		return (1);
	if (close(data->pipe_fd[1]))
		return (1);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		return (1);
	execve(data->path_cmd2, data->cmd2, envp);
	perror(data->path_cmd2);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(data->pipe_fd[0]);
	return (1);
}

int	child_one(t_data *data, char **envp)
{
	if (dup2(data->fd_in, STDIN_FILENO) == -1)
		return (1);
	if (close(data->pipe_fd[0]))
		return (1);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		return (1);
	execve(data->path_cmd1, data->cmd1, envp);
	perror(data->path_cmd1);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(data->pipe_fd[1]);
	return (1);
}

int	pipex(t_data *data, char **envp)
{
	if (pipe(data->pipe_fd))
		return (1);
	data->child1 = fork();
	if (data->child1 < 0)
		perror("fork :");
	if (data->child1 == 0)
	{
		if (child_one(data, envp))
			return (1);
	}
	data->child2 = fork();
	if (data->child2 < 0)
		perror("fork :");
	if (data->child2 == 0)
	{
		if (child_two(data, envp))
			return (1);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	wait(NULL);
	return (0);
}
