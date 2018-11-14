/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitswap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:32:30 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 10:30:46 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

uint64_t		swap_uint64(uint64_t val)
{
	val = ((val << 8) & 0xFF00FF00FF00FF00)
		| ((val >> 8) & 0x00FF00FF00FF00FF);
	val = ((val << 16) & 0xFFFF0000FFFF0000)
		| ((val >> 16) & 0x0000FFFF0000FFFF);
	return ((val << 32) | ((val >> 32) & 0xFFFFFFFF));
}

uint32_t		swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00)
			| ((val >> 8) & 0x00FF00FF);
	return ((val << 16) | ((val >> 16) & 0xFFFF));
}
