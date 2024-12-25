#include "../inc/tools.h"

void	rra(t_stack **stack_a)
{
	if (stack_a && *stack_a)
	{
		shift_down_index(*stack_a);
		*stack_a = (*stack_a)->blink;
	}
}

void	rrb(t_stack **stack_b)
{
	if (stack_b && *stack_b)
	{
		shift_down_index(*stack_b);
		*stack_b = (*stack_b)->blink;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
