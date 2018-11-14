/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:39:51 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 15:34:10 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static const uint32_t	g_r[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static const uint32_t	g_k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static void				init_h_values(uint32_t v[4])
{
	v[0] = 0x67452301;
	v[1] = 0xefcdab89;
	v[2] = 0x98badcfe;
	v[3] = 0x10325476;
}

void					md5_main_loop(uint32_t *chunk, uint32_t v[4])
{
	uint32_t		i;
	uint32_t		temp;
	uint32_t		f_g[2];

	i = 0;
	while (i < 64)
	{
		if (i < 16)
			calc_fg_i_16(i, v, f_g);
		else if (i < 32)
			calc_fg_i_32(i, v, f_g);
		else if (i < 48)
			calc_fg_i_48(i, v, f_g);
		else
			calc_fg_i_64(i, v, f_g);
		temp = v[3];
		v[3] = v[2];
		v[2] = v[1];
		v[1] = v[1] + cl_rotate(v[0] + f_g[0] + g_k[i] + chunk[f_g[1]],
											g_r[i]);
		v[0] = temp;
		i++;
	}
}

char					*md5(char *message)
{
	t_md		md;
	uint32_t	offset;
	uint32_t	*chunk;
	uint32_t	v[4];
	uint32_t	temp[4];

	md = padding_md5_sha2(message, FALSE);
	init_h_values(v);
	offset = 0;
	while (offset < md.md_lenght)
	{
		chunk = (uint32_t *)(md.str + offset);
		ft_memcpy(temp, v, 4 * sizeof(uint32_t));
		md5_main_loop(chunk, temp);
		add_tab_values(v, temp, 4);
		offset += 512 / 8;
	}
	return (h_values_hexstr(v, 4, FALSE));
}
