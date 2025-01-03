#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "tools.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	set_ordred_index(t_stack *stack, int sz_stack);
void	pb_until_three(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	get_effective_cost(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b);
void	smart_rotate(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

#endif