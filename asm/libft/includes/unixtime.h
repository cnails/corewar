/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unixtime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/12/05 22:22:51 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIXTIME_H
# define UNIXTIME_H
# include <stdarg.h>

typedef struct	s_utime
{
	int hour;
	int minute;
	int second;
	int weekday;
	int day;
	int month;
	int year;
}				t_utime;

t_utime			new_unixtime(void);
void			set_unixtotime(t_utime *utime, int unix_time);
t_utime			unix_to_struct(int unix_time);
char			*ft_unix_to_isodate(va_list ap);

#endif
