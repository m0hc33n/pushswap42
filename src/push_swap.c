#include "../inc/push_swap.h"

static void	smart_rotate(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		while (cost_a-- && cost_b--)
			rr(stack_a, stack_b, true);
	else if (cost_a < 0 && cost_b < 0)
		while (cost_a++ && cost_b++)
			rrr(stack_a, stack_b, true);
	if (cost_a > 0)
		while (cost_a--)
			ra(stack_a, true);
	else
		while (cost_a++)
			rra(stack_a, true);
	if (cost_b > 0)
		while (cost_b--)
			rb(stack_b, true);
	else
		while (cost_b++)
			rrb(stack_b, true);
}

static void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	cost_a;
	int	cost_b;

	while (*stack_b)
	{
		get_target_b_link(*stack_a, *stack_b, &cost_a, &cost_b);
		smart_rotate(stack_a, stack_b, cost_a, cost_b);
		pa(stack_a, stack_b, true);
	}
}

static void	final_touch(t_stack **stack_a)
{
	t_stack	*tmp;
	int		sz_stack;

	if ((*stack_a)->ordred_index == 0)
		return ;
	tmp = *stack_a;
	while (tmp->ordred_index != 0)
		tmp = tmp->flink;
	sz_stack = (*stack_a)->blink->index - 1;
	if (tmp->index > sz_stack / 2)
		while ((*stack_a)->ordred_index)
			rra(stack_a, true);
	else
		while ((*stack_a)->ordred_index)
			ra(stack_a, true);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	pb_until_three(stack_a, stack_b);
	sort_three(stack_a);
	push_back(stack_a, stack_b);
	final_touch(stack_a);
}

