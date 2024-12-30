#include "../inc/tools.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack && stack->flink && stack->flink->index > 0)
	{
		tmp = stack->data;
		stack->data = stack->flink->data;
		stack->flink->data = tmp;
		tmp = stack->ordred_index;
		stack->ordred_index = stack->flink->ordred_index;
		stack->flink->ordred_index = tmp;
	}
}

void	sa(t_stack *stack_a, bool out)
{
	if (stack_a)
	{
		swap(stack_a);
		if (out)
			write(STDOUT_FILENO, SA, 2);
	}
}

void	sb(t_stack *stack_b, bool out)
{
	if (stack_b)
	{
		swap(stack_b);
		if (out)
			write(STDOUT_FILENO, SA, 3);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, bool out)
{
	if (stack_a && stack_b)
	{
		swap(stack_a);
		swap(stack_b);
		if (out)
			write(STDOUT_FILENO, SA, 3);
	}
}
