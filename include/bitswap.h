/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:32:54 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 10:26:45 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSWAP_H
# define BITSWAP_H

# include <stdint.h>

uint64_t			swap_uint64(uint64_t val);
uint32_t			swap_uint32(uint32_t val);

#endif
