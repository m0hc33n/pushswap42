#include "../inc/push_swap.h"

static void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	b_target_pos;
	int	cost_a;
	int	cost_b;

	while (*stack_b)
	{
		b_target_pos = get_target_b_link(*stack_a, *stack_b, &cost_a, &cost_b);
		
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	pb_until_three(stack_a, stack_b);
	sort_three(stack_a);
	push_back(stack_a, stack_b);
}

