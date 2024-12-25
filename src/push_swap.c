#include "../inc/push_swap.h"

/*
	Swap (sa, sb, ss): Swap the first two elements at the top of each stack.
	Push (pa, pb): Push an element from one stack to the other.
	Rotate (ra, rb, rr): Rotate the stack, shifting all elements up by one.
	Reverse Rotate (rra, rrb, rrr): Reverse rotate the stack, shifting all elements down by one.
*/


int main(int ac, char **av)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;
	//int	sz_stack;

	//z_stack = ac - 1;
	stack_a = NULL;
	if (!arg_validator(ac, av, &stack_a) || !stack_a)
		return (err());
	if (is_sorted(stack_a))
		return (0);
	int is_rot = 0;
	while (!is_rot)
	{
		printf("{ data : %d , index : %d , address : %p ,  flink : %p , blink %p }\n", stack_a->data, stack_a->index, stack_a ,stack_a->flink, stack_a->blink);
		stack_a = stack_a->flink;
		if (stack_a->index == 0)
			is_rot = 1;
	}
	free_links(&stack_a);
	return 0;
}
