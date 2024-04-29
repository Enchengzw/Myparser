/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:26:59 by ezhou             #+#    #+#             */
/*   Updated: 2024/04/25 16:27:55 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd *ft_parse(char *input)
{
	t_cmd	*head;
	t_cmd	*new;
	char	**cmds;
	int		i;

	head = NULL;
	cmds = ft_split(input, '|'); 
	if (!cmds)
		return (NULL);
	while(cmds[i])
	{
		new = ft_process_cmd(cmds[i]);
		
	}
	return (head); 
}