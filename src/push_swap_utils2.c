#include "../inc/push_swap.h"

static int	get_a_link_target(t_stack *stack_a, int b_ordred_index_link)
{
	int	is_rot;
	int	target_pos;
	int	prev_target;

	is_rot = 0;
	prev_target = INT32_MAX;
	while (!is_rot)
	{
		if (stack_a->ordred_index > b_ordred_index_link 
			&& stack_a->ordred_index < prev_target)
		{
			target_pos = stack_a->index;
			prev_target = stack_a->ordred_index;
		}
		stack_a = stack_a->flink;
		if (stack_a->index == 0)
			is_rot = 1;
	}
	return (target_pos);
}

static void	calc_cost(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b)
{
	int		sz_stack_b;
	int		sz_stack_a;
	int		link_target;

	sz_stack_b = stack_b->blink->index + 1;
	sz_stack_a = stack_a->blink->index + 1;
	if (stack_b->index > sz_stack_b / 2)
		*cost_b = stack_b->index - sz_stack_b;
	else
		*cost_b = stack_b->index;
	link_target = get_a_link_target(stack_a, stack_b->ordred_index);
	if (link_target > sz_stack_a / 2)
		*cost_a = link_target - sz_stack_a;
	else
		*cost_a = link_target;
}

void	get_target_b_link(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b)
{
	int		is_rot;
	int		lowest_cost;
	int		tcost;
	int		tmp_cost_a;
	int		tmp_cost_b;

	is_rot = 0;
	lowest_cost = INT32_MAX;
	while (!is_rot)
	{
		calc_cost(stack_a, stack_b, &tmp_cost_a, &tmp_cost_b);
		tcost = abs(*cost_a) + abs(*cost_b);
		if (lowest_cost > tcost)
		{
			*cost_a = tmp_cost_a;
			*cost_b = tmp_cost_b;
			lowest_cost = tcost;
		}
		stack_b = stack_b->flink;
		if (stack_b->index == 0)
			is_rot = 1;
	}
}