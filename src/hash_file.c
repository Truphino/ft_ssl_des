/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:56:31 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/19 11:43:36 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include "errors.h"
#include <errno.h>

static char			*append(char *dest, char *app)
{
	size_t		total_len;
	char		*final;

	total_len = ft_strlen(dest) + ft_strlen(app);
	final = (char *)ft_memalloc(total_len + 1);
	ft_memcpy(final, dest, ft_strlen(dest));
	ft_memcpy(final + ft_strlen(dest), app, ft_strlen(app));
	free(dest);
	return (final);
}

char				*file_to_string(int fd)
{
	char		*buf;
	char		*file;
	int			r;

	file = (char *)ft_memalloc(1);
	if ((buf = (char *)ft_memalloc(BUF_SIZE)) == NULL)
		return (NULL);
	while ((r = read(fd, buf, BUF_SIZE)) > 0)
	{
		file = append(file, buf);
		ft_memset(buf, 0, BUF_SIZE);
	}
	return (file);
}

char				*hash_file(t_flag_warpper fw, char *filename)
{
	char		*line;
	int			fd;

	fd = 0;
	if (filename)
		if ((fd = open(filename, O_RDONLY)) < 0)
		{
			print_error(errno, fw.p_name, filename);
			return (NULL);
		}
	line = file_to_string(fd);
	if (line)
		return (fw.func_ptr(line));
	return (NULL);
}
