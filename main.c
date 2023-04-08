/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:59:44 by robegarc          #+#    #+#             */
/*   Updated: 2023/04/08 17:28:39 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/global.h"
#include "incl/functions.h"

int	no_space_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ' ')
			str++;
		cnt++;
		str++;
	}
	return (cnt);
}

int	check_params(t_args *ptr, char *env[])
{
	char	s[1000];
	
	if (!ft_strncmp(ptr->line, "exit", 4))
	{
		free(ptr->line);
		printf("free & exit\n");
		exit(0);
	}
	if (!ft_strncmp(ptr->line, "echo", 4))
		execve("/bin/echo", ptr->mat, env);
	if (!ft_strncmp(ptr->line, "ls", 2))
		execve("/bin/ls", ptr->mat, env);
	if (!ft_strncmp(ptr->line, "cd ..", 5))
		chdir("..");
	if (!ft_strncmp(ptr->line, "pwd", 3))
		printf("PWD-> %s\n", getcwd(s, 1000));
	return (0);
}

void	free_mat_args(t_args *ptr)
{
	int	i;

	i = -1;
	while (ptr->mat[++i])
		free(ptr->mat[i]);
	free(ptr->mat);
}

int main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	t_args	*ptr;
	int		j;

	ptr = (t_args *)malloc(sizeof(t_args));
	while (1)
	{
		ptr->line = readline(MINISHELL);
		add_history(ptr->line);
		printf("\n#####################################################################\n\n");
		printf("Entire input-> |%s|\n", ptr->line);
		printf("len with no space-> [%d]\n", no_space_len(ptr->line));
		printf("absolute len-> %d\n", ft_strlen(ptr->line));
		printf("\n#####################################################################\n\n");
		ptr->mat = ft_split(ptr->line, ' ');
		j = -1;
		while (ptr->mat[++j])
		{
			printf("the %d string-> |%s|\n", j, ptr->mat[j]);
			check_flags1(ptr->mat[j], ptr);
			
			// printf("ptr.id-> %d\n", ptr->arg_id);
			init(ptr->mat[j], ptr);
			check_params(ptr, env);
		}
		free_mat_args(ptr);
		free(ptr->line);
	}
	free(ptr);
	return (0);
}
