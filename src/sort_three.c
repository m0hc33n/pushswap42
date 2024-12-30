#include "../inc/push_swap.h"

static int	get_big_index(t_stack *stack)
{
	if (stack->data > stack->flink->data
		&& stack->data > stack->blink->data)
		return (0);
	else if (stack->flink->data > stack->data
		&& stack->flink->data > stack->blink->data)
		return (1);
	else
		return (2);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	highest = get_big_index(*stack);
	if (highest == 0)
		ra(stack);
	else if (highest == 1)
		rra(stack);
	if ((*stack)->data > (*stack)->flink->data)
		sa(*stack);
}
