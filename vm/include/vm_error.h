/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:03:31 by cnails            #+#    #+#             */
/*   Updated: 2020/12/06 14:03:42 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ERROR_H
# define VM_ERROR_H

/*
** number of errors
*/
# define NOE_FD 2

/*
** corewar
*/
# define E_ERR "Error: "
# define E_USAGE "usage: bla-bla-bla"

/*
** functions
*/
# define E_READ "couldn't read bytecode"
# define E_MALLOC "in malloc"
# define E_SSPLIT "in ft_strsplit"
# define E_STRSUB "in strsub"

/*
** parse files
*/
# define E_PAR_MAGIC_HEADER "Error magic header"
# define E_PAR_NAME "Read name"
# define E_PAR_CHAMP_SIZE "Read champ size"
# define E_PAR_COMMENT "Read comment"

#endif
