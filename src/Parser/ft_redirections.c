/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:39:58 by ezhou             #+#    #+#             */
/*   Updated: 2024/04/25 16:55:19 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_length(char *input)
{
	int i;

	i = 0;
	while (input[i] && input[i] != ' ')
		i++;
	return (i);
}

char	*ft_get_name(char *input)
{
	int	lenght;
}

int	ft_get_outfile(char *input, int j, int *i)
{
	int		fd;
	char	*name;

	if (j == 1)
	{
		name = ft_get_name(input + 1);
		fd = open(input, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		*i++;
	}
	else
	{	
		name = ft_get_name(input + 2);
		fd = open(input, O_WRONLY | O_CREAT | O_APPEND, 0644);
		*i += 2;
	}
	
}