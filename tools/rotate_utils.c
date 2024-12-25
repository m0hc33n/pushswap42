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

void	shift_down_index(t_stack *stack)
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
