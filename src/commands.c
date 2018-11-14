/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:03:43 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/25 17:03:47 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include "parse_cli.h"

static const		t_command g_command_list[] =
{
	{MESSAGE_DIGEST, &md5, "md5", "MD5",
		"usage: md5 [-pqr] [-s string] [files ...]"},
	{MESSAGE_DIGEST, &sha256, "sha256", "SHA256",
		"usage: sha256 [-pqr] [-s string] [files ...]"},
	{SPECIAL, &exit_ptr, "exit", "", ""},
	{SPECIAL, &exit_ptr, "q", "", ""},
};

static const size_t	g_num_commands =
sizeof(g_command_list) / sizeof(t_command);

static void			print_command_type(t_command_type cmd_type)
{
	ft_putchar('\n');
	if (cmd_type == STANDARD)
		ft_putstr("Standard");
	else if (cmd_type == MESSAGE_DIGEST)
		ft_putstr("Message Digest");
	else if (cmd_type == CIPHER)
		ft_putstr("Cipher");
	else
		ft_putstr("ERROR");
	ft_putendl(" commands:");
}

static void			print_command_list_type(t_command_type cmd_type)
{
	size_t				i;

	i = 0;
	print_command_type(cmd_type);
	while (i < g_num_commands)
	{
		if (cmd_type == g_command_list[i].cmd_type)
			ft_putendl(g_command_list[i].cmd_name);
		i++;
	}
}

void				print_command_list(void)
{
	size_t				i;

	i = 0;
	print_command_list_type(STANDARD);
	print_command_list_type(MESSAGE_DIGEST);
	print_command_list_type(CIPHER);
}

void				parse_command_name(char *cmd_name, t_flag_warpper *fw)
{
	size_t				i;

	i = 0;
	fw->func_ptr = NULL;
	fw->flags = 0;
	while (i < g_num_commands)
	{
		if (ft_strcmp(cmd_name, g_command_list[i].cmd_name) == 0)
		{
			fw->func_ptr = g_command_list[i].func_ptr;
			fw->func_name = g_command_list[i].func_name;
			fw->cmd_name = g_command_list[i].cmd_name;
		}
		i++;
	}
}

void				print_usage(t_flag_warpper fw)
{
	uint32_t		i;

	i = 0;
	while (i < g_num_commands)
	{
		if (fw.func_ptr == g_command_list[i].func_ptr)
		{
			ft_putendl(g_command_list[i].func_usage);
		}
		i++;
	}
}
