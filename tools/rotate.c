#include "../inc/tools.h"

void	shift_up_index(t_stack *stack)
{
	if (stack && stack->blink->index > 0)
	{
		stack = stack->flink;
		while (stack->index < stack->flink->index)
		{
			stack->index--;
			stack = stack->flink;
		}
		stack->index--;
		stack->flink->index = stack->index + 1;
	}
}

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
