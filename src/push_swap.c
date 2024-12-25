#include "../inc/push_swap.h"

/*
	print stack // to remove
*/
void	print_stack(t_stack *stack)
{
	int is_rot = 0;
	if (stack)
	{
		while (!is_rot)
		{
			printf("\t\t{ data : %d , index : %d , address : %p ,  flink : %p , blink %p , (ni : %d)}\n", stack->data, 
				stack->index, stack ,stack->flink, stack->blink, stack->flink->index);
			stack = stack->flink;
			if (stack->index == 0)
				is_rot = 1;
		}
	}
}

/*
	Swap (sa, sb, ss): Swap the first two elements at the top of each stack.
	Push (pa, pb): Push an element from one stack to the other.
	Rotate (ra, rb, rr): Rotate the stack, shifting all elements up by one.
	Reverse Rotate (rra, rrb, rrr): Reverse rotate the stack, shifting all elements down by one.
*/


int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//int	sz_stack;

	//z_stack = ac - 1;
	stack_a = NULL;
	stack_b = NULL;
	if (!arg_validator(ac, av, &stack_a) || !stack_a)
		return (err());
	if (is_sorted(stack_a))
		return (0);
	
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);

	print_stack(stack_b);
	print_stack(stack_a);	

	free_links(&stack_a);
	return 0;
}
