/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/12/05 21:46:30 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 1
# define FD 1024

typedef struct			s_my_list
{
	char				*content;
	int					file;
	struct s_my_list	*next;
}						t_my_list;

int						ft_intchr(char *str, char c, size_t len);
int						get_next_line(const int fd, char **line);
t_my_list				*ft_fdnew(int fd);
int						gnl(int fd, t_my_list **fd_line, char **line,
							char *str);
int						read_line(char **str, t_my_list **ptr_list,
							int num, size_t *len);

#endif
