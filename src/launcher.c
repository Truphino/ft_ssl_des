/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:18:38 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/25 17:18:41 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_warpper.h"
#include "macros.h"
#include "parse_cli.h"
#include "libft.h"
#include "ft_ssl_md5.h"
#include "errors.h"
#include "commands.h"

void	print_description(char *func_name, t_hash_type type, char *mes)
{
	ft_putstr(func_name);
	ft_putstr(" (");
	if (type == STR)
		ft_putchar('"');
	ft_putstr(mes);
	if (type == STR)
		ft_putchar('"');
	ft_putstr(") = ");
}

void	launch_fn_str(char *filename, t_flag_warpper *fw, t_hash_type type)
{
	char				*md;

	flag_set(fw, LAUNCH);
	if (type == FILENAME)
		md = hash_file(*fw, filename);
	else
		md = fw->func_ptr(filename);
	if (!md)
		exit(1);
	if (filename && !flag_check(*fw, FLAG_R) && !(flag_check(*fw, FLAG_Q)))
		print_description(fw->func_name, type, filename);
	ft_putstr(md);
	if (filename && !(flag_check(*fw, FLAG_Q)) && flag_check(*fw, FLAG_R))
	{
		ft_putchar(' ');
		if (type == STR)
			ft_putchar('"');
		ft_putstr(filename);
		if (type == STR)
			ft_putchar('"');
	}
	ft_putchar('\n');
}

void	launch_p(t_flag_warpper *fw)
{
	char				*md;
	char				*str;

	if (!(flag_check(*fw, ALRD_P)))
	{
		str = file_to_string(0);
		if ((md = fw->func_ptr(str)) == NULL)
			exit(1);
		ft_putstr(str);
		ft_putendl(md);
		flag_set(fw, ALRD_P);
	}
	else
	{
		ft_putendl(fw->func_ptr(""));
	}
}

int		launch_s(t_flag_warpper *fw, char **argv, int i, int j)
{
	if (argv[i][j + 1])
	{
		launch_fn_str(argv[i] + j + 1, fw, STR);
	}
	else if (argv[i + 1])
	{
		launch_fn_str(argv[i + 1], fw, STR);
		i += 1;
	}
	else
	{
		print_error(NO_ARGS, fw->cmd_name, "s");
		print_usage(*fw);
		exit(1);
	}
	return (i);
}
