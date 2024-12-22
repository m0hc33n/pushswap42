#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // exit()
# include <stdbool.h>
# include <stdint.h>

# define ERROR "ERROR\n"
# define ERRORLEN 6

# define ZERO 48
# define PLUS 43
# define MINUS 45

int		**arg_validator(int ac, char **av);
void	free_stack(int	**stack);
bool	fetch_value(char *arg, int *value);

#endif