/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_warpper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:14:18 by trecomps          #+#    #+#             */
/*   Updated: 2018/10/19 10:07:24 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_WARPPER_H
# define FLAG_WARPPER_H

# define ALRD_P 1 << 0
# define FLAG_P 1 << 1
# define FLAG_Q 1 << 2
# define FLAG_R 1 << 3
# define FLAG_S 1 << 4
# define LAUNCH 1 << 5
# define L_CMDL 1 << 6

typedef struct		s_flag_warpper
{
	char			*p_name;
	char			*(*func_ptr)(char *);
	char			*func_name;
	char			*cmd_name;
	unsigned int	flags;
}					t_flag_warpper;

t_flag_warpper		flag_set(t_flag_warpper *fw, unsigned int flag);
unsigned int		flag_check(t_flag_warpper fw, unsigned int flag);
t_flag_warpper		init_flag_warpper(char *p_name);

#endif
