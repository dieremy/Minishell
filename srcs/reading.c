/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:59:44 by robegarc          #+#    #+#             */
/*   Updated: 2023/04/08 17:33:45 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/global.h"
#include "../incl/functions.h"

void	free_mat_cmd(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->mat[++i])
		free(cmd->mat[i]);
	free(cmd->mat);
}
int	check_flags2(char *s, t_args *ptr, int i)
{
	if (s[i] == '>')
	{
		if (s[i + 1] == '>')
		{
			ptr->arg_id = append;
			i++;
		}
		else
			ptr->arg_id = redirection_out;
		i++;
	}
	else if (s[i] == '<')
	{
		if (s[i + 1] == '<')
		{
			ptr->arg_id = heredoc;
			i++;
		}
		else
			ptr->arg_id = redirection_in;
		i++;
	}
	return (0);
}

int	check_flags1(char *s, t_args *ptr)
{
	int	i;

	i = 0;
	ptr->arg_id = param;
	if (s[i] == '|')
	{
		if (s[i + 1] == '|')
		{
			ptr->arg_id = or;
			i++;
		}
		else
			ptr->arg_id = pipe_line;
		i++;
	}
	else if (s[i] == '&' && s[i + 1] == '&')
	{
		ptr->arg_id = double_and;
		i++;
	}
	check_flags2(s, ptr, i);
	return (0);
}

char	*return_cond(char *s, t_args *ptr)
{
	char	*out;
	int		i;
	(void)ptr;
	
	i = -1;
	out = ft_calloc(1, sizeof(char));
	while (s[++i])
	{
		out[i] = s[i];
		if (s[i] == '|')
			break;
	}
	out[i] = 0;
	return (out);
}

int init(char *str, t_args *ptr)
{
	t_cmd	*cmd;
	int		x;
	int		k;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	x = -1;
	while (str[++x])
	{
		k = -1;
		cmd->mat = ft_split(str, ' ');
		while (cmd->mat[++k])
		{
			cmd->line = return_cond(cmd->mat[k], ptr);
			printf("cmd.line-> %s\n", cmd->line);
		}
		free_mat_cmd(cmd);
	}
	free(cmd);
	return (0);
}
