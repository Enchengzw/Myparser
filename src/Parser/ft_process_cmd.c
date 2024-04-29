/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:56:52 by ezhou             #+#    #+#             */
/*   Updated: 2024/04/25 16:50:21 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_get_file(char *input, t_cmd *cmd, int *i, char **separators)
{
	int		j;

	j = ft_which_separator(input, separators);
	if (j == 1 || j == 3)
	{
		cmd->fds->outfile = ft_get_outfile(input, j, i);
	}
	else if (j == 0 || j == 2)
	{
		cmd->fds->infile = ft_get_infile(input, j, i);
	}
	return (SUCCESS);
}

int ft_which_separator(char *string, char **separators)
{
	int j;

	j = 0;
	while (separators[j])
	{
		if (ft_strncmp(string, separators[j], ft_strlen(separators[j])) == 0)
			return (j);
		i++;
	}
	return (-1);
}

static void	ft_init_separators(char **separators)
{
	separators[0] = "<";
	separators[1] = ">";
	separators[2] = "<<";
	separators[3] = ">>";
	separators[4] = NULL;
}

t_cmd *ft_process_cmd(char *input)
{
	t_cmd	*new;
	char	**args;
	int		i;
	char	**separators[5];
	
	ft_init_separators(separators);
	args = (char **)malloc(sizeof(char *) * ft_count_words(input) + 1);
	if (!args)
		return (NULL);
	new = ft_new_cmd();
	if (!new)
		return (free(args), NULL);
	while (input[i] && !ft_isspace(input[i]))
	{
		if (ft_which_separators(input[i], separators, &i) != -1)
			ft_get_file(new, input + i, &i, separators);
		i++;
	}
	return (new);
}
