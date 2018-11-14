/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_sigma.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:54:52 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 14:56:26 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "hash_tools.h"
#include "sha_helpers.h"

uint32_t			sha_sigma(uint32_t x, t_sigma_type stype)
{
	if (stype == MAJ_0)
		return (cr_rotate(x, 2) ^ cr_rotate(x, 13) ^ cr_rotate(x, 22));
	else if (stype == MAJ_1)
		return (cr_rotate(x, 6) ^ cr_rotate(x, 11) ^ cr_rotate(x, 25));
	else if (stype == MIN_0)
		return (cr_rotate(x, 7) ^ cr_rotate(x, 18) ^ (x >> 3));
	else if (stype == MIN_1)
		return (cr_rotate(x, 17) ^ cr_rotate(x, 19) ^ (x >> 10));
	else
		return (0);
}

uint32_t			sha_ch(uint32_t x, uint32_t y, uint32_t z)
{
	x = (x & y) ^ ((~x) & z);
	return (x);
}

uint32_t			sha_maj(uint32_t x, uint32_t y, uint32_t z)
{
	x = (x & y) ^ (x & z) ^ (y & z);
	return (x);
}
