#include "../inc/tools.h"

static void	shift_down_index(t_stack *stack)
{
	if (stack && stack->blink->index > 0)
	{
		while (stack->index < stack->flink->index)
		{
			stack->index++;
			stack = stack->flink;
		}
		stack->index = 0;
	}
}

void	rra(t_stack **stack_a, bool out)
{
	if (stack_a && *stack_a)
	{
		shift_down_index(*stack_a);
		*stack_a = (*stack_a)->blink;
		if (out)
			write(STDOUT_FILENO, RRA, 4);
	}
}

void	rrb(t_stack **stack_b, bool out)
{
	if (stack_b && *stack_b)
	{
		shift_down_index(*stack_b);
		*stack_b = (*stack_b)->blink;
		if (out)
			write(STDOUT_FILENO, RRB, 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool out)
{
	ra(stack_a, out);
	rb(stack_b, out);
}
