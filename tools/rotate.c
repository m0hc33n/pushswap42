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

void	ra(t_stack **stack_a, bool out)
{
	if (stack_a && *stack_a)
	{
		shift_up_index(*stack_a);
		*stack_a = (*stack_a)->flink;
		if (out)
			write(STDOUT_FILENO, RA, 3);
	}
}

void	rb(t_stack **stack_b, bool out)
{
	if (stack_b && *stack_b)
	{
		shift_up_index(*stack_b);
		*stack_b = (*stack_b)->flink;
		if (out)
			write(STDOUT_FILENO, RB, 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool out)
{
	ra(stack_a, false);
	rb(stack_b, false);
	if (out)
		write(STDOUT_FILENO, RR, 3);
}
