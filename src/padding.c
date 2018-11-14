/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:35:11 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 15:32:45 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

t_md			padding_md5_sha2(char const *message, int is_be)
{
	uint64_t	message_lenght;
	t_md		md;

	message_lenght = uint64_strlen(message);
	md.md_lenght = message_lenght * 8 + 1;
	while (md.md_lenght % 512 != 448)
		md.md_lenght++;
	md.md_lenght /= 8;
	md.str = ft_memalloc(md.md_lenght + 8);
	ft_memcpy(md.str, message, message_lenght);
	md.str[message_lenght] = 128;
	message_lenght *= 8;
	if (is_be)
		message_lenght = swap_uint64(message_lenght);
	ft_memcpy(md.str + md.md_lenght, &message_lenght, 8);
	return (md);
}
