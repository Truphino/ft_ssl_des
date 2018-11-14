/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_fg_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:28:06 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 11:11:24 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void		calc_fg_i_16(uint32_t i, uint32_t v[4], uint32_t f_g[2])
{
	uint32_t	f;
	uint32_t	g;

	if (i < 16)
	{
		f = (v[1] & v[2]) | ((~v[1]) & v[3]);
		g = i;
	}
	else
	{
		f = 0;
		g = 0;
	}
	f_g[0] = f;
	f_g[1] = g;
}

void		calc_fg_i_32(uint32_t i, uint32_t v[4], uint32_t f_g[2])
{
	uint32_t	f;
	uint32_t	g;

	if (i < 32)
	{
		f = (v[3] & v[1]) | ((~v[3]) & v[2]);
		g = (5 * i + 1) % 16;
	}
	else
	{
		f = 0;
		g = 0;
	}
	f_g[0] = f;
	f_g[1] = g;
}

void		calc_fg_i_48(uint32_t i, uint32_t v[4], uint32_t f_g[2])
{
	uint32_t	f;
	uint32_t	g;

	if (i < 48)
	{
		f = v[1] ^ v[2] ^ v[3];
		g = (3 * i + 5) % 16;
	}
	else
	{
		f = 0;
		g = 0;
	}
	f_g[0] = f;
	f_g[1] = g;
}

void		calc_fg_i_64(uint32_t i, uint32_t v[4], uint32_t f_g[2])
{
	uint32_t	f;
	uint32_t	g;

	if (i < 64)
	{
		f = v[2] ^ (v[1] | (~v[3]));
		g = (7 * i) % 16;
	}
	else
	{
		f = 0;
		g = 0;
	}
	f_g[0] = f;
	f_g[1] = g;
}
