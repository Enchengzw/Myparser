/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:36:46 by ezhou             #+#    #+#             */
/*   Updated: 2024/04/25 11:45:23 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_new_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->previous = NULL;
	new->fds = (t_fds *)malloc(sizeof(t_fds));
	if (!new->fds)
	{
		free(new);
		return (NULL);
	}
	new->fds->infile = 0;
	new->fds->outfile = 0;
	new->fds->pipe[0] = 0;
	new->fds->pipe[1] = 0;
	new->fds->std_in = 0;
	new->fds->std_out = 0;
	new->cmd_path = NULL;
	new->arg = NULL;
	new->env = NULL;
	new->num_arg = 0;
	return (new);
}

void	ft_add_cmd(t_cmd **head, t_cmd *new)
{
	t_cmd	*current;

	if (!*head)
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
	new->previous = current;
	*head->num_arg++;
}