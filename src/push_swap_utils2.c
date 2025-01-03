#include "../inc/push_swap.h"

static int	get_a_min_ordred_index(t_stack *stack_a)
{
	bool	is_rot;
	t_stack	*smallest;

	is_rot = false;
	smallest = stack_a;
	while (!is_rot)
	{
		if (stack_a->ordred_index < smallest->ordred_index)
			smallest = stack_a;
		stack_a = stack_a->flink;
		if (stack_a->index == 0)
			is_rot = true;
	}
	return (smallest->index);
}

static size_t	get_a_link_target(t_stack *stack_a, int b_ordred_index_link)
{
	int		is_rot;
	size_t	target_pos;
	size_t	prev_target;

	is_rot = 0;
	prev_target = INT64_MAX;
	target_pos = INT64_MAX;
	while (!is_rot)
	{
		if (stack_a->ordred_index > b_ordred_index_link
			&& (size_t)stack_a->ordred_index < prev_target)
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

static int	calc_cost_a(t_stack *stack_a, t_stack *stack_b)
{
	int		sz_stack_a;
	size_t	link_target;

	sz_stack_a = stack_a->blink->index + 1;
	link_target = get_a_link_target(stack_a, stack_b->ordred_index);
	if (link_target == INT64_MAX)
		link_target = get_a_min_ordred_index(stack_a);
	if (link_target > (size_t)sz_stack_a / 2)
		return (link_target - sz_stack_a);
	else
		return ((int)link_target);
}

static int	calc_cost_b(t_stack *stack_b, int sz_stack_b)
{
	if (stack_b->index > sz_stack_b / 2)
		return (stack_b->index - sz_stack_b);
	else
		return (stack_b->index);
}

void	get_effective_cost(t_stack *stack_a, t_stack *stack_b,
			int *cost_a, int *cost_b)
{
	int		is_rot;
	int		sz_b;
	int		lowest_cost;
	int		tmp_cost_a;
	int		tmp_cost_b;

	is_rot = 0;
	lowest_cost = INT32_MAX;
	sz_b = stack_b->blink->index + 1;
	while (!is_rot)
	{
		tmp_cost_a = calc_cost_a(stack_a, stack_b);
		tmp_cost_b = calc_cost_b(stack_b, sz_b);
		if (lowest_cost > abs(tmp_cost_a) + abs(tmp_cost_b))
		{
			*cost_a = tmp_cost_a;
			*cost_b = tmp_cost_b;
			lowest_cost = abs(tmp_cost_a) + abs(tmp_cost_b);
		}
		stack_b = stack_b->flink;
		if (stack_b->index == 0)
			is_rot = 1;
	}
}
