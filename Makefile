CC = cc 
CFLAGS = -Wall -Wextra -Werror

HDR = inc/push_swap.h
TLS_HDR = inc/tools.h

SRC = 	src/main.c src/push_swap.c \
		src/push_swap_utils.c src/push_swap_utils2.c \
		src/sort_three.c
TOOLS = tools/arg_validator.c tools/utils.c \
		tools/links_utils.c \
		tools/ft_split.c tools/is_sorted.c \
		tools/swap.c tools/push.c tools/rotate.c tools/rrotate.c

SRC_OBJ = $(SRC:.c=.o)
TLS_OBJ = $(TOOLS:.c=.o)

EXEC = push_swap

all : $(EXEC)

$(EXEC) : $(SRC_OBJ) $(TLS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ) : $(HDR)

$(TLS_OBJ) : $(TLS_HDR)

clean : 
	rm -f $(SRC_OBJ)  $(TLS_OBJ)

fclean : clean
	rm -f $(EXEC)

re : fclean all

.PHONY : clean