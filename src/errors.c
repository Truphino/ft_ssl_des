/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:56:53 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/19 13:07:29 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

static const	t_dispatch_error g_error_list[] =
{
	{NO_COMMAND, "usage: #p command [command opts] [command args]\n"},
	{INVALID_COMMAND, "#p: Error: '#m' is an invalid command.\n"},
	{NO_FILE_FOUND, "#p: #m: No such file or directory\n"},
	{ACCES_ERROR, "#p: #m: Permission denied\n"},
	{ILLEGAL_OPTION, "#p: illegal option -- #m\n"},
	{NO_ARGS, "#p: : option requires an argument -- #m\n"}
};

static const size_t	g_num_errors =
sizeof(g_error_list) / sizeof(t_dispatch_error);

void		print_command_replace(char *command, char *p_name, char *message)
{
	size_t		i;
	size_t		start;

	i = 0;
	start = 0;
	while (command[i])
	{
		while (command[i] && command[i] != '#')
			i++;
		if (!command[i])
			ft_putstr(command + start);
		else
		{
			if (i > start)
				write(1, command + start, i - start);
			if (command[i + 1] == 'p')
				ft_putstr(p_name);
			else if (command[i + 1] == 'm')
				ft_putstr(message);
			else
				ft_putchar(command[i + 1]);
			i += 2;
			start = i;
		}
	}
}

void		ft_putsbstr(char *str, size_t end)
{
	if (end == 0 || end > ft_strlen(str))
		end = ft_strlen(str) - 1;
	write(1, str, end);
}

void		print_error(t_errors_type er_type, char *p_name, char *message)
{
	size_t		i;

	i = 0;
	while (i < g_num_errors)
	{
		if (er_type == g_error_list[i].er_type)
			print_command_replace(g_error_list[i].error_message,
				p_name, message);
		i++;
	}
}
