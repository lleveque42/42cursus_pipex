/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:57:25 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/27 22:29:15 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

typedef struct s_path
{
	char	**path;
	char	**cmd1;
	char	**cmd2;
	int		fd_in;
	int		fd_out;
	pid_t	child1;
	pid_t	child2;
	int		end[2];
}	t_data;

int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		no_env(void);
int		wrong_input(void);
int		wrong_infile(char *infile);
int		cmd_not_found(char *cmd);
int		check_args(char **av);
int		check_access(char *infile);
int		parse_cmd(t_data *data, char *cmd1, char *cmd2);
void	init_data(t_data *data);
void	get_data(char **envp, t_data *path);
void	get_cmd(t_data *data, char *cmd1, char *cmd2);


#endif
