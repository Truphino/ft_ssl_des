/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_helpers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:59:25 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 12:51:38 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_HELPERS_H
# define SHA_HELPERS_H

# include <stdint.h>

typedef enum		e_sigma_type {
	MAJ_0,
	MAJ_1,
	MIN_0,
	MIN_1
}					t_sigma_type;

uint32_t			sha_sigma(uint32_t x, t_sigma_type stype);
uint32_t			sha_maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t			sha_ch(uint32_t x, uint32_t y, uint32_t z);

#endif
