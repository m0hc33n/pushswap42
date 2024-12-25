#include "../inc/tools.h"

void	ra(t_stack **stack_a)
{
	if (stack_a && *stack_a)
	{
		shift_up_index(*stack_a);
		*stack_a = (*stack_a)->flink;
	}
}

void	rb(t_stack **stack_b)
{
	if (stack_b && *stack_b)
	{
		shift_up_index(*stack_b);
		*stack_b = (*stack_b)->flink;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
