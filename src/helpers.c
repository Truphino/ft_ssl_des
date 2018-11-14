/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:45:19 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/24 11:45:21 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtoupper(const char *str)
{
	char	*ret;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	ret = (char *)(ft_memalloc(len + 1));
	while (i < len)
	{
		ret[i] = ft_toupper(str[i]);
		i++;
	}
	return (ret);
}

void		free_if(void **mem)
{
	if (mem && *mem)
		ft_memdel(mem);
}

void		free_null_terminated_tab(void **ptr)
{
	size_t	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i] != NULL)
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
	}
}

char		*exit_ptr(char *message)
{
	exit(1);
	return (message);
}
