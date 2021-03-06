.PHONY: all clean fclean re

# compil: valgrind ./vm/corewar vm/trash_test/Backward.cor vm/trash_test/ex.cor vm/trash_test/42.cor

# COLORS
BLUE = "\033[0;34m"
RESET = "\033[0m"

# COMPILER SETTINGS
CC := clang
CFLAGS := -Wall -Wextra -Werror

# LIB (LIBFT, GET_NEXT_LINE, PRINTF)
L_DIR := ../lib/
L_NAME = lib.a
L_RULE := $(addsuffix .lib, $(L_DIR))

# PROGRAM NAME
PROG_NAME := corewar

# HEADER DIR
H_DIR := include/

# HEADER NAME
H_NAME = vm op parse_args
H_NAME := $(addprefix $(H_DIR), $(addsuffix .h, $(H_NAME)))

# SOURCES DIR
SRC_DIR := src/

SRC_PARSE_DIR = parse/
SRC_PARSE_DIR := $(addprefix $(SRC_DIR), $(SRC_PARSE_DIR))

SRC_LOGIC_DIR = logic/
SRC_LOGIC_DIR := $(addprefix $(SRC_DIR), $(SRC_LOGIC_DIR))

SRC_LOGIC_OP_DIR = operation/
SRC_LOGIC_OP_DIR := $(addprefix $(SRC_LOGIC_DIR), $(SRC_LOGIC_OP_DIR))

SRC_UTILS_DIR = utils/
SRC_UTILS_DIR := $(addprefix $(SRC_DIR), $(SRC_UTILS_DIR))

# SOURCES
SRC_MAIN =  main \
			game \
			champ \
			carriage \
			vm
SRC_MAIN := $(addsuffix .c, $(SRC_MAIN))

SRC_PARSE = parse_args \
			parse_args_extra \
			parse_args_flags \
			parse_files
SRC_PARSE := $(addsuffix .c, $(SRC_PARSE))

SRC_LOGIC = op \
			arg \
			calc \
			exec_oper \
			check

SRC_LOGIC := $(addsuffix .c, $(SRC_LOGIC))

SRC_LOGIC_OP =	add_zjmp_and_fork_ld \
				or_st_sti_sub_xor \
				ldi_lfork_live_lld_lldi
				
SRC_LOGIC_OP := $(addsuffix .c, $(SRC_LOGIC_OP))

SRC_UTILS = extra \
			debug

SRC_UTILS := $(addsuffix .c, $(SRC_UTILS))

# FILE PATH TO LIB, PROGRAM SRC/OBJ FILES
PROG_SRC := $(addprefix $(SRC_DIR), $(SRC_MAIN)) \
			$(addprefix $(SRC_DIR), $(SRC_VISUAL)) \
			$(addprefix $(SRC_PARSE_DIR), $(SRC_PARSE)) \
			$(addprefix $(SRC_LOGIC_DIR), $(SRC_LOGIC)) \
			$(addprefix $(SRC_LOGIC_OP_DIR), $(SRC_LOGIC_OP)) \
			$(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS))

L_NAME := $(addprefix $(L_DIR), $(L_NAME))

all: $(L_RULE) $(PROG_NAME)

%.lib:
	@$(MAKE) -sC $(L_DIR)

$(PROG_NAME) : $(PROG_SRC) $(H_NAME) $(L_NAME)
	@$(CC) $(CFLAGS) $(PROG_SRC) $(L_NAME) -o $(PROG_NAME) -I $(H_DIR) -lncurses
	@echo $(BLUE)"COREWAR COMPILED"$(RESET)

clean:
	@$(MAKE) -sC $(L_DIR) clean

fclean: clean
	@$(MAKE) -sC $(L_DIR) fclean
	@rm -f $(PROG_NAME)

re: fclean all
