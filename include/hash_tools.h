/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:35:37 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/18 12:02:51 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TOOLS_H
# define HASH_TOOLS_H

# include <stdint.h>

uint32_t		cl_rotate(uint32_t x, uint32_t c);
uint32_t		cr_rotate(uint32_t x, uint32_t c);
void			add_tab_values(uint32_t *a, uint32_t *b, uint32_t size);

#endif
