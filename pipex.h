/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:57:25 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/31 13:47:31 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_data
{
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
	int		fd_in;
	int		fd_out;
	pid_t	child1;
	pid_t	child2;
	int		pipe_fd[2];
}	t_data;

int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		no_env(void);
int		wrong_input(void);
int		cmd_not_found(char *cmd);
int		cant_init_data(void);
int		cant_find_path(void);
int		no_file(char *file);
int		check_args(char **av);
int		check_access(t_data *data, char *infile, char *outfile, char **envp);
int		parse_cmd(t_data *data);
int		init_data(t_data *data, char *cmd1, char *cmd2);
int		get_data(char **envp, t_data *path);
void	get_cmd(t_data *data, char *cmd1, char *cmd2);
int		pipex(t_data *data, char **envp);

#endif
