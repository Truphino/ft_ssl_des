/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_warpper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:15:53 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/25 17:15:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_warpper.h"
#include "libft.h"

unsigned int			flag_check(t_flag_warpper fw, unsigned int flag)
{
	return (fw.flags & flag);
}

t_flag_warpper			flag_set(t_flag_warpper *fw, unsigned int flag)
{
	fw->flags = fw->flags | flag;
	return (*fw);
}

t_flag_warpper			init_flag_warpper(char *p_name)
{
	t_flag_warpper		fw;

	fw.p_name = p_name;
	fw.func_ptr = NULL;
	fw.func_name = NULL;
	fw.flags = 0;
	return (fw);
}
