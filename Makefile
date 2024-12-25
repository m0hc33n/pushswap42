CC = cc 
CFLAGS = -Wall -Wextra -Werror

HDR = inc/push_swap.h
TLS_HDR = inc/tools.h

SRC = src/push_swap.c
TOOLS = tools/arg_validator.c tools/links_utils.c tools/utils.c \
		tools/ft_split.c tools/is_sorted.c

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