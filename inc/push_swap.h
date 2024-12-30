#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "tools.h"
# include <stdbool.h>
# include <stdio.h> // exit()
# include <stdlib.h>
# include <unistd.h>

void	set_ordred_index(t_stack *stack, int sz_stack);
void	sort_three(t_stack **stack);

#endif