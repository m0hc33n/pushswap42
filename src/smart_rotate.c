#include "../inc/push_swap.h"

static void	smart_rr(t_stack **stack_a, t_stack **stack_b,
				int *cost_a, int *cost_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < *cost_a && b < *cost_b)
	{
		rr(stack_a, stack_b, true);
		a++;
		b++;
	}
	*cost_a -= a;
	*cost_b -= b;
}

static void	smart_rrr(t_stack **stack_a, t_stack **stack_b,
				int *cost_a, int *cost_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a > *cost_a && b > *cost_b)
	{
		rrr(stack_a, stack_b, true);
		a--;
		b--;
	}
	*cost_a += abs(a);
	*cost_b += abs(b);
}

static void	if_cost_a(t_stack **stack, int cost)
{
	if (cost > 0)
	{
		while (cost--)
			ra(stack, true);
	}
	else if (cost < 0)
		while (cost++)
			rra(stack, true);
}

static void	if_cost_b(t_stack **stack, int cost)
{
	if (cost > 0)
	{
		while (cost--)
			rb(stack, true);
	}
	else if (cost < 0)
		while (cost++)
			rrb(stack, true);
}

void	smart_rotate(t_stack **stack_a, t_stack **stack_b,
			int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		smart_rr(stack_a, stack_b, &cost_a, &cost_b);
	if (cost_a < 0 && cost_b < 0)
		smart_rrr(stack_a, stack_b, &cost_a, &cost_b);
	if_cost_a(stack_a, cost_a);
	if_cost_b(stack_b, cost_b);
}
