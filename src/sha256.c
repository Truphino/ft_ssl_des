/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 10:46:52 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 15:34:29 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include "sha_helpers.h"
#include "sha_macro.h"

static const uint32_t	g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

static void		init_h_values(uint32_t v[8])
{
	v[0] = 0x6a09e667;
	v[1] = 0xbb67ae85;
	v[2] = 0x3c6ef372;
	v[3] = 0xa54ff53a;
	v[4] = 0x510e527f;
	v[5] = 0x9b05688c;
	v[6] = 0x1f83d9ab;
	v[7] = 0x5be0cd19;
}

static void		init_w(uint32_t w[64], uint32_t *chunk)
{
	uint32_t	i;

	i = 0;
	while (i < 64)
	{
		if (i < 16)
			w[i] = swap_uint32(chunk[i]);
		else
			w[i] = sha_sigma(w[i - 2], MIN_1) + w[i - 7]
					+ sha_sigma(w[i - 15], MIN_0) + w[i - 16];
		i++;
	}
}

void			sha256_main_loop(uint32_t *chunk, uint32_t v[8])
{
	uint32_t	i;
	uint32_t	temp1;
	uint32_t	temp2;
	uint32_t	w[64];

	init_w(w, chunk);
	i = 0;
	while (i < 64)
	{
		temp1 = H + sha_sigma(E, MAJ_1) + sha_ch(E, F, G) + g_k[i] + w[i];
		temp2 = sha_sigma(A, MAJ_0) + sha_maj(A, B, C);
		H = G;
		G = F;
		F = E;
		E = D + temp1;
		D = C;
		C = B;
		B = A;
		A = temp1 + temp2;
		i++;
	}
}

char			*sha256(char *message)
{
	t_md		md;
	uint32_t	v[8];
	uint32_t	*chunk;
	uint32_t	offset;
	uint32_t	temp[8];

	md = padding_md5_sha2(message, TRUE);
	init_h_values(v);
	offset = 0;
	while (offset < md.md_lenght)
	{
		chunk = (uint32_t *)(md.str + offset);
		ft_memcpy(temp, v, 8 * sizeof(uint32_t));
		sha256_main_loop(chunk, temp);
		add_tab_values(v, temp, 8);
		offset += 512 / 8;
	}
	return (h_values_hexstr(v, 8, TRUE));
}
