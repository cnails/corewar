/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define LEX_ERR			"Lexical error at"
# define SYN_ERR			"Syntax error at"
# define USAGE				"Usage: ./asm [options] <file.s>\n"
# define HEADER_ERR			"Error: wrong header file\n"
# define EXEC_MAGIC_ERR		"Error: COREWAR_EXEC_MAGIC > UINT_MAX\n"
# define MALLOC_ERR			"Error: malloc error\n"

void						error_function(char *err, char *string, int n, \
										int column);
void						length_og_error(int f);

#endif
