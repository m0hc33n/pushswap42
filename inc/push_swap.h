#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "tools.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // exit()
# include <stdbool.h>

void	push_swap(int **stack_a, int **stack_b);


// ACTIONS
void	sa(int **stack_a, int sz_stack);
void	sb(int **stack_b, int sz_stack);
void	ss(int **stack_a, int **stack_b, int sz_stack);

void	pa(int **stack_a, int **stack_b, int sz_stack);
void	pb(int **stack_a, int **stack_b, int sz_stack);

#endif