#include "../inc/push_swap.h"

/*
	set to each node on the stack its ordred position when it sorted;
	ex : ->data : ->3 ->0 ->-4 ->5 : ->ordred_index : ->2 ->1 ->0 ->3
*/
void	set_ordred_index(t_stack *stack, int sz_stack)
{
	int		i;
	int		j;
	t_stack	*p;
	t_stack	*tmp;

	p = stack;
	i = 0;
	while (i++ < sz_stack)
	{
		tmp = stack;
		j = 0;
		while (j++ < sz_stack)
		{
			if (p->data > tmp->data)
				p->ordred_index++;
			tmp = tmp->flink;
		}
		p = p->flink;
	}
}

static int	get_mean(t_stack *stack)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (stack->index < stack->flink->index)
	{
		sum += stack->ordred_index;
		i++;
		stack = stack->flink;
	}
	sum += stack->ordred_index;
	if (sum % i == 0)
		return (sum / i);
	else
		return ((sum / i) + 1);
}

/*
	push all element - 3 from stack a to stack b
	
	push smallest numbers first by calculating mean (average)
*/
void	pb_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		mean;

	while ((*stack_a)->blink->index > 2)
	{
		mean = get_mean(*stack_a);
		if ((*stack_a)->ordred_index < mean)
			pb(stack_a, stack_b, true);
		else if ((*stack_a)->flink->ordred_index < mean)
		{
			ra(stack_a, true);
			pb(stack_a, stack_b, true);
		}
		else if ((*stack_a)->blink->ordred_index < mean)
		{
			rra(stack_a, true);
			pb(stack_a, stack_b, true);
		}
		else
			ra(stack_a, true);
	}
}
