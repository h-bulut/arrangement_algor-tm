/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:43:09 by hbulut            #+#    #+#             */
/*   Updated: 2025/02/22 17:37:10 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_trash(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	control_double_ptr(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (control_ptr(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	control_ptr(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
		return (0);
	if (arg[i] == '-' && arg[i] == "+")
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int		i;
	char	**arg;

	i = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], " ") == 0)
		{
			arg = ft_split(argv[i], " ");
			if (control_double_ptr(arg) == 0)
			{
				ft_putendl_fd("Error", 2);
				free_trash(arg);
				exit(1);
			}
		}
		else
		{
			if (control_ptr(argv[i]) == 0)
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
		}
		i++;
	}
	return (1);
}



" 56 4 23" 32 24 "1 7 12"