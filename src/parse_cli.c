/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:52:27 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/19 13:08:15 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cli.h"
#include "errors.h"
#include "ft_ssl_md5.h"
#include "commands.h"
#include "launcher.h"

int				process_arg(char **argv, t_flag_warpper *fw, int i)
{
	int					j;

	j = 0;
	while (argv[i][++j])
	{
		if (argv[i][j] == 'q')
			flag_set(fw, FLAG_Q);
		else if (argv[i][j] == 'r')
			flag_set(fw, FLAG_R);
		else if (argv[i][j] == 'p')
			launch_p(fw);
		else if (argv[i][j] == 's')
			return (launch_s(fw, argv, i, j));
		else
		{
			argv[i][j + 1] = '\0';
			print_error(ILLEGAL_OPTION, (*fw).p_name, &(argv[i][j]));
			print_usage(*fw);
			exit(1);
		}
	}
	return (i);
}

void			parse_args(int argc, char **argv, t_flag_warpper *fw)
{
	int					i;
	char				*md;

	i = 0;
	if (argc == 0)
	{
		if ((md = hash_file(*fw, NULL)) != NULL)
		{
			ft_putendl(md);
			flag_set(fw, L_CMDL | LAUNCH);
		}
	}
	else
	{
		while (i < argc)
		{
			if (argv[i][0] == '-')
				i = process_arg(argv, fw, i);
			else
				launch_fn_str(argv[i], fw, FILENAME);
			i++;
		}
	}
	if (!(flag_check(*fw, ALRD_P)) && !(flag_check(*fw, LAUNCH)))
		launch_fn_str(NULL, fw, FILENAME);
}

void			parse_command_cli(int argc, char **argv, t_flag_warpper *fw)
{
	parse_command_name(argv[0], fw);
	if (fw->func_ptr == NULL)
	{
		print_error(INVALID_COMMAND, fw->p_name, argv[0]);
		print_command_list();
	}
	else if (fw->func_ptr == &exit_ptr)
		fw->func_ptr(NULL);
	else
		parse_args(argc - 1, argv + 1, fw);
}

void			parse_no_command(t_flag_warpper *fw)
{
	char				**split;
	size_t				i;
	char				*line;
	int					ret;

	i = 0;
	ret = 1;
	while (ret && !flag_check(*fw, L_CMDL))
	{
		ft_putstr("ft_openssl => ");
		ret = get_next_line(0, &line);
		if (ret && line[0] != '\0')
		{
			split = ft_strsplit(line, ' ');
			while (split[i] != NULL)
				i++;
			parse_command_cli(i, split, fw);
			free_null_terminated_tab((void **)split);
		}
	}
}

t_flag_warpper	parse_cli(int argc, char **argv)
{
	t_flag_warpper		fw;

	fw = init_flag_warpper(argv[0]);
	if (argc < 2)
		parse_no_command(&fw);
	else
		parse_command_cli(argc - 1, argv + 1, &fw);
	return (fw);
}
