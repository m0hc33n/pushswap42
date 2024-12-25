#include "../inc/tools.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a && stack_a->flink && stack_a->flink->index > 0)
	{
		tmp = stack_a->data;
		stack_a->data = stack_a->flink->data;
		stack_a->flink->data = tmp;
	}
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b && stack_b->flink && stack_b->flink->index > 0)
	{
		tmp = stack_b->data;
		stack_b->data = stack_b->flink->data;
		stack_b->flink->data = tmp;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
