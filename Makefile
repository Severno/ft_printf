NAME=libftprintf.a
LIBFT_NAME=libft/libft.a

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
LIGHT_GREEN:="\033[1;92m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"

END_IN:=\033[0;0m
BLACK_IN:=\033[1;30m
RED_IN:=\033[1;31m
GREEN_IN:=\033[1;32m
PURPLE_IN:=\033[1;35m
CYAN_IN:=\033[1;36m
WHITE_IN:=\033[1;37m
# ==================

FILES = alignment \
		calc_float_width \
		calc_signed_precision \
		calc_signed_width \
		calc_unsigned_precision \
		calc_unsigned_width \
		check_conventions \
		flag_cs \
		flag_di \
		flag_f \
		flag_f_handle \
		flag_o \
		flag_p \
		flag_percent \
		flag_u \
		flag_x \
		ft_ftoa \
		ft_printf \
		get_flags \
		handle_float_conditions \
		handle_float_zeros \
		parse_flags \
		pf_putnbr_base \
		pf_putstr \
		pf_putunbr \
		pf_strcat \
		pf_strchr \
		pf_strchr_flags \
		precision \
		print_d \
		print_f \
		print_o \
		print_p \
		print_percent \
		print_u \
		print_x \
		removes_flags \
		utils


OBJ_PATH=objects/
SRC_PATH=src/
HEAD_PATH= includes/

SRC=$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ=$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))
OBJ_LIB=objects/*/*.o

CC:=gcc
C_FLAGS:=-Wall -Wextra -Werror -I $(HEAD_PATH)
CACHE=.cache_exists

#test:
#	@echo $(FILES_PUSH_SWAP) "PUSH_SWAP"
#	@echo $(FILES_CHECKER) "CHECKER"

all: libft_make $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done" $(END)
	@echo "\n"
	@echo $(RED)"You can write something in main.c file and run:"$(END) $(CYAN)"\"gcc main.c libftprintf.a -o my_prog; ./my_prog\". "$(END)

libft_make:
	@cd libft/; make; cp -R objects ../objects;

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEAD_PATH)
	@printf '$(CYAN_IN)%-20s$(RED_IN)%-50s $(GREEN_IN)%-8s' "- Compile function:" "$<" "$(COUNTER)/$(LENGTH)"
	@echo "\r\c"
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	@$(CC) $(C_FLAGS) -c $< -o $@



%.c:
	@echo $(RED) "Missing file : $@"

$(CACHE):
	@mkdir $(OBJ_PATH)
	@touch $(CACHE)

clean:
	@rm -rf $(OBJ_PATH)
	@rm -f $(CACHE)

fclean: clean
	@cd libft/; make fclean; cd ..;
	@rm libftprintf.a

re: fclean
	$(MAKE) all

norm:
	@echo $(RED)
	@norminette src/ $(HEAD_PATH) | grep -v Norme -B1 || echo $(END)$(LIGHT_GREEN)"Norm - OK!"$(END)
	@echo $(END)

.PHONY: all clean fclean re test norm libft_make