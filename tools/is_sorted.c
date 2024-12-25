#include "../inc/tools.h"

bool	is_sorted(t_stack *stack)
{
	if (stack)
	{
		while (stack->index < stack->flink->index)
		{
			if (stack->data > stack->flink->index)
				return (false);
			stack = stack->flink;
		}
	}
	return (true);
}
