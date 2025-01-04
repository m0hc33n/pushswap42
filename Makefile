CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC_HDR = inc/push_swap.h
TLS_HDR = inc/tools.h
CHECKER_HDR = inc/checker.h

SRC = 	src/main.c src/push_swap.c \
		src/push_swap_utils.c src/push_swap_utils2.c \
		src/sort_three.c src/smart_rotate.c
CHECKER_SRC = checker_src/main.c checker_src/get_next_line.c \
		checker_src/get_next_line_utils.c
TOOLS = tools/arg_validator.c tools/utils.c \
		tools/links_utils.c \
		tools/ft_split.c tools/is_sorted.c \
		tools/swap.c tools/push.c tools/rotate.c tools/rrotate.c

SRC_OBJ 	= $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
TLS_OBJ 	= $(TOOLS:.c=.o)

EXEC = push_swap
CHECKER = checker

all : $(EXEC)

bonus : $(CHECKER)

$(EXEC) : $(SRC_OBJ) $(TLS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER) : $(CHECKER_OBJ) $(TLS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SRC_OBJ) : $(SRC_HDR) $(TLS_HDR)

$(TLS_OBJ) : $(TLS_HDR)

$(CHECKER_OBJ) : $(CHECKER_HDR) $(TLS_HDR)

clean : 
	rm -f $(SRC_OBJ)  $(TLS_OBJ) $(CHECKER_OBJ)

fclean : clean
	rm -f $(EXEC) $(CHECKER)

re : fclean all

.PHONY : clean