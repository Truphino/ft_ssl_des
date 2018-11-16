/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:22:38 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/19 12:27:59 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include "parse_cli.h"

int			main(int argc, char **argv)
{
	size_t			len = 0;
	char			message[] = "OkOTest123!@#";

	(void)argc;
	(void)argv;
	ft_putendl(message);
	ft_putendl(base64_e(message, &len));
	ft_putendl(base64_d(base64_e(message, &len), &len));
//	fw = parse_cli(argc, argv);
}
