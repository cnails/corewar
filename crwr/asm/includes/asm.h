/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "options.h"
# include "error.h"
# include "libftprintf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define LOL			"Invalid indirect arg, it is not a number"
# define FT_PARSE_ARGS1	"Invalid number of args(too many)"
# define FT_PARSE_ARGS2	"Invalid number of args(few)"
# define MAX_ARGS		3
# define MAX_OP			17
# define BUFF			4096
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define PURPLE			"\033[35;1m"
# define EOC			"\e[0m"
# define LEN_N			sizeof(N_CMD_STR)
# define LEN_C			sizeof(C_CMD_STR)
# define TOO_MANY_ARGS	2
# define FEW_ARGS		3
# define INVALID_TYPE	4
# define MAX_ARGS		3
# define MAX_OP			17
# define BUFF 			4096
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define PURPLE			"\033[35;1m"
# define EOC			"\e[0m"
# define TOO_MANY_ARGS	2
# define FEW_ARGS		3
# define INVALID_TYPE	4
# define CH_STR			26

typedef struct			s_arg
{
	int					type;
	char				*label;
	int					size;
	int					value;
	int					arg_number;
}						t_arg;

typedef struct			s_sort
{
	char				*label;
	struct s_sort		*next;
}						t_sort;

typedef struct			s_instr
{
	char				*name;
	int					id;
	int					size;
	t_arg				args[3];
	char				*label;
	int					id_instr;
	int					sum_size;
	t_sort				*labels;
}						t_instr;

typedef struct			s_label
{
	char				*name;
	int					label_id;
	int					label_row;
	int					instr_id;
	struct s_label		*next;
}						t_label;

typedef struct			s_data
{
	int					read_fd;
	int					write_fd;
	int					file_size;
	int					line_count;
	t_label				*label;
	t_header			*header;
	t_instr				*instrs;
	int					instr_num;
	int					*symbol_number;
	char				*split;
	char				*all_labels;
	char				*file;
}						t_data;

typedef struct			s_op
{
	char				*name_oper;
	int					col_args;
	int					type_arg[MAX_ARGS];
	int					opcode;
	int					cycle_to_die;
	char				*comment;
	int					bit_type;
	int					tdir_size;
}						t_op;

const t_op				g_op_tab[MAX_OP];

int						label_validation(char *str);
t_sort					*push_block(char *label);
void					push_to_the_end(char *label, t_sort **sort);
void					deleting_of_sort(t_sort **sort);
void					exit_func(char *str);
void					free_memory_and_write_error(char *err, char *line, \
													t_data *data, int ind_str);
char					*ft_saved_name(char *str);
void					close_fd(int a, int b, char *filename);
void					eliminate_spaces(char *split, int *i);
int						validate_number(char *name);
int						length_of_massiv(char **args);
int						count_number_lines(t_data *data, int num);
void					initialization_function(t_data *data, int n);
int						parse_line(char *str, t_data *data);
int						check_is_a_comment(char *string);
int						parsing_of_header(t_header *main, char *string, \
																int line_num);
void					read_whole_file(t_data *data);
void					parsing_of_body(char *initial_string, t_data *data);
char					*parsing_of_label(char *arr, int *sym_num);
void					parsing_function(char *split, int *i, t_data *data);
void					parse_all_arguments(char *split, int *i, t_data *data);
void					count_size_of_block(t_data *data);
void					get_number(char *argument, t_data *data, int n);
void					validate_filename(char *filename);
void					ft_check_header_file(void);
void					ft_check_args(char **av, int ac);
void					validate_filename(char *filename);
int						label_validation(char *str);
void					ft_check_all_data(t_data *data);
void					ft_check_flags(char ***av, int ac);
int						check_args(t_data *data);
void					free_two_dim_array(char **array);
void					free_memory_in_main_structure(t_data *data);
void					ft_cor_extension(char *filename, t_data *data);
int						put_something_to_file(t_data *data, int fd);
int						writing_header_to_file(char *str, int size, int fd, \
																		int f);
void					magic_number_put_fd(long nb, int fd);
void					put_to_fd(long nbr, int fd);
int						go_through_spaces(char *line, int id);
void					count_sum_size(t_data *data);
void					put_to_fd(long nbr, int fd);
void					magic_number_put_fd(long nb, int fd);
int						put_something_to_file(t_data *data, int fd);
void					put_magic_to_fd(long nb, int fd);
void					wput_args_to_fd(t_data *data, int ind_instr, \
											int code_op, int fd);
int						count_label_size(t_data *data, t_arg *args, int cur_size, \
										int tdir_size);
int						args_to_code(t_arg *args);
int						put_dir_code(int args, int type, \
										int fd, int sizeof_t_dir);
int						get_code_op(char *name);
int						write_header_in_file(char *str, int size, \
												int fd, int f);
void					instrsToFd(t_data *data, int fd);

#endif
