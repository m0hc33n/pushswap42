#include "../inc/push_swap.h"

/*
	set to each node on the stack its ordred position when it sorted;
	ex : ->data : ->3 ->0 ->-4 ->5 : ->ordred_index : ->2 ->1 ->0 ->3
*/
void	set_ordred_index(t_stack *stack, int sz_stack)
{
	int	i;
	int	j;
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

/*
	push the smallest possible number to stack b until stack_a->index == 2 (3 elements)
*/
void	pb_until_three(t_stack **stack_a, t_stack **stack_b)
{
	
}
